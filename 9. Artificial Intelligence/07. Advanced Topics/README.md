# Advanced Topics

## Semi-Supervised Learning

> 적은 양의 Labled data와 많은 양의 Unlabeled data로 학습시키는 technique

### Generative Models

- Gaussian Mixture Model
- Deep Generative Model

### Graph Based

- Label Propagation

#### Graph Neural Networks (GNNs)

> Pass massages between pairs of nodes and agglomerate

- Notation
  - `G = (A, X)` : Graph
  - `A` : Adjacency matrix
  - `X` : Node feature matrix
- Task
  - Predict node label of unlabeled nodes

### Self-Training (Pseudo-Labeling)

- Self-Training
- Co-Training

#### Self-Training

1. Train the model with labeled data
2. Predict the unlabeled data using the trained model
3. Add most confident (unlabeled) sample to the labeled data
4. Repeat 1-3

### Consistency Regularization

e.g., Pi-Model, Mean Teacher, ...

1. Train the model with labeled data
2. Predict the unlabeled data using the trained model
3. Add noise to the unlabeled data (i.e., data augmentation)
4. Train the model with the augmented unlabeled data where the ground truth is the predicted labels from 2.
5. Repeat 1-4

## Self-Supervised Learning

### Why Self-Supervised Learning?

- Expense of producing a new dataset for each task
- Take advantage of vast of unlabeled data on the internet
- Successful story of supervised learning comes from the utility of pre-trained models for various downstream tasks
  - e.g., detection, segmentation, ...

### Goal of Self-Supervised Learning

- Learn equally good (if not better) features without supervision
- Generalize better potentially because you learn more about the world

### Denoising Autoencoder

- Input: Corrupted data (Noised data)
- Output: Original data

### Predict Misssing Pieces: Context Encoders

### Relative Position of Image Patches

- Input: Shuffled image patches
- Output: Relative position of image patches

### Jigsaw Puzzles

- Input: Shuffled image patches
- Output: Original image patches

### Rotation Prediction

- Input: Rotated image
- Output: Rotation angle

### S4L: Self-Supervised Semi-Supervised Learning

## [Domain Adaptation (DA)](https://github.com/zhaoxin94/awesome-domain-adaptation)

- Adjust a model from the **source domain knowledge** to a different but related **target domain**
- Unsupservised DA
  - **No labeled** in the target domain

### Two baseline DA approaches

1. **Domain-invariant** feature learning
2. **Pixel-level DA** using GAN

## Knowledge Transfer

### Transfer Learning

### Knowledge Distillation

Knowledge distillation is a process of distilling or transferring the knowledge from a large model(s) to a lighter, easier-to-deploy single model, **without significant loss in performance**.

# References

1. 인공지능 응용 (ICE4104), 인하대학교 정보통신공학과 홍성은 교수님