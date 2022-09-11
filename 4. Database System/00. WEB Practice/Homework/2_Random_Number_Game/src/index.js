let range = document.getElementById("js-range");
let title = document.getElementById("js-title").querySelector("span"); // id가 js-title인 태그 내부의 span 태그 선택
let guess = document.getElementById("js-guess").querySelector("input"); // id가 js-guess인 태그 내부의 input 태그 선택
const button = document.querySelector("button");
const answer = document.getElementById("js-answer").querySelector("span"); // id가 js-answer인 태그 내부의 span 태그 선택
const result = document.getElementById("js-result").querySelector("span"); // id가 js-result인 태그 내부의 span 태그 선택

const updateValue = (e) => {
    e.preventDefault(); // 창이 이동하는 것을 막아줌
    const max = range.value;
    title.innerHTML = max;
}

const playGame = (e) => {
    e.preventDefault(); // 창이 이동하는 것을 막아줌
    const max = range.value;
    var rand = Math.floor(Math.random() * (parseInt(max, 10) + 1)); // 0 ~ max 사이의 랜덤 float 값을 생성, 0과 max를 포함.
    console.log(max);
    answer.innerHTML = `You choose: ${guess.value}, The machine chose: ${rand}`;
    if (parseInt(guess.value, 10) === rand) {
        result.innerHTML = "<b>You Won!</b>";
    } else {
        result.innerHTML = "<b>You Lost!</b>";
    }
};

range.addEventListener("input", updateValue);
button.addEventListener("click", playGame);

