#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 100

typedef struct pair {
    char* key;
    int value;
} PAIR;

int main(void) {
    printf("Enter a sentence\n");
    char sentence[100];
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);
    sentence[strlen(sentence) - 1] = '\0';
    printf("You entered %s\n", sentence);
    char* words[MAX_SENTENCE_LENGTH - 1];
    char* word = strtok(sentence, " ");
    int word_count = 0;
    while (word != NULL) {
        words[word_count] = (char*) malloc(sizeof(char) * (strlen(word) + 1));
        strcpy(words[word_count], word);
        word_count += 1;
        word = strtok(NULL, " ");
    }
    printf("There were %d words: ", word_count);
    for (int i = 0; i < word_count; i += 1) {
        printf("%s ", words[i]);
    }
    printf("\n");
    PAIR* word_frequencies = (PAIR*) malloc(sizeof(PAIR) * word_count);
    int word_frequency_count = 0;
    for (int i = 0; i < word_count; i += 1) {
        bool existence = 0;
        for (int j = 0; j < word_frequency_count; j += 1) {
            if (strcmp(word_frequencies[j].key, words[i]) == 0) {
                word_frequencies[j].value += 1;
                existence = true;
                break;
            }
        }
        if (!existence) {
            word_frequencies[word_frequency_count].key = (char*) malloc(sizeof(char) * (strlen(words[i]) + 1));
            strcpy(word_frequencies[word_frequency_count].key, words[i]);
            word_frequencies[word_frequency_count].value = 1;
            word_frequency_count += 1;
        }
    }
    printf("Frequencies: ");
    PAIR* most_frequent_word_ptr = &word_frequencies[0];
    for (int i = 0; i < word_frequency_count; i += 1) {
        if (most_frequent_word_ptr->value < word_frequencies[i].value) {
            most_frequent_word_ptr = &word_frequencies[i];
        }
        printf("%s %d ", word_frequencies[i].key, word_frequencies[i].value);
    }
    printf("\nThe word with the max freq: %s", most_frequent_word_ptr->key);
    return 0;
}
