*This project has been created as part of the 42 curriculum by gpecelli, gipimpin.*

<div align="center">
  <h1>🔄 Push_swap</h1>
  <p><em>Because Swap_push doesn't feel as natural</em></p>

  <img src="https://img.shields.io/badge/Language-C-blue.svg" alt="Language C">
  <img src="https://img.shields.io/badge/School-42-black.svg" alt="42 School">
  <img src="https://img.shields.io/badge/Norminette-Passing-success.svg" alt="Norminette Passing">
</div>

<br/>

## 📑 Table of Contents
1. [Description](#-description)
2. [The Rules & Operations](#%EF%B8%8F-the-rules--operations)
3. [Algorithms and Justification](#-algorithms-and-justification)
4. [Performance Benchmark](#%E2%8F%B1%EF%B8%8F-performance-benchmark)
5. [Instructions](#-instructions)
6. [Resources and AI Usage](#-resources-and-ai-usage)

---

## 📖 Description
**Push_swap** is a core algorithmic project from the 42 curriculum. The objective is deceivingly simple: sort a random stack of integers in ascending order using two stacks (`a` and `b`) and a highly restricted set of operations.

The real challenge lies in **algorithmic complexity**. The goal is not just to sort the stack, but to sort it using the *absolute minimum* number of operations possible. 

To achieve maximum efficiency, this project implements a custom **Adaptive Sorting Strategy** that dynamically selects the optimal sorting algorithm based on the stack's size and an initial **disorder metric** (a calculated ratio of misplaced pairs).

---

## 🛠️ The Rules & Operations

We start with two stacks: `a` (containing a random set of integers) and `b` (empty). The allowed operations are:

| Operation | Description |
| :---: | :--- |
| `sa` / `sb` / `ss` | **Swap**: Swap the first two elements at the top of stack `a`, `b`, or both (`ss`). |
| `pa` / `pb` | **Push**: Take the first element at the top of one stack and push it to the other. |
| `ra` / `rb` / `rr` | **Rotate**: Shift all elements up by one. The first element becomes the last. |
| `rra` / `rrb` / `rrr`| **Reverse Rotate**: Shift all elements down by one. The last element becomes the first. |

---

## 🧠 Algorithms and Justification

Our adaptive strategy embeds three distinct sorting methodologies to ensure optimal operation counts across different levels of stack disorder and sizes:

### 1. Simple Sort (Min/Max Extraction)
- **Complexity Target:** $\mathcal{O}(n^2)$
- **Regime:** Low disorder ($< 0.2$).
- **How it works:** A highly optimized variation of Selection Sort. It iterates through Stack `a` to find the absolute minimum value and pushes it to Stack `b`, utilizing the shortest path (direct or reverse rotation). Once Stack `a` is empty, everything is pushed back.
- **Justification:** While theoretically $\mathcal{O}(n^2)$, this algorithm is extremely efficient for stacks that are already almost sorted or very small, as the computational overhead of complex target calculations is completely avoided.

### 2. Chunk Sort (Medium Algorithm)
- **Complexity Target:** $\mathcal{O}(n\sqrt{n})$
- **Regime:** Medium disorder ($0.2 \le disorder < 0.5$).
- **How it works:** This method partitions the stack into proportional chunks based on the square root of the stack size ($\sqrt{n}$). Elements belonging to the current chunk are pushed to Stack `b`. To optimize pushes, it places elements of the current chunk at the top of `b`, and elements of the *next* chunk at the bottom of `b` simultaneously using `rb` or `rr`. Finally, it extracts the maximums from Stack `b` back to Stack `a`.
- **Justification:** Dividing the stack into proportional chunks drastically reduces the search space for the largest elements during the push-back phase, striking a perfect balance between speed and move efficiency for moderately scrambled data.

### 3. Turk Algorithm (Complex Algorithm)
- **Complexity Target:** $\mathcal{O}(n \log n)$
- **Regime:** High disorder ($\ge 0.5$).
- **How it works:** This algorithm constantly evaluates the "cost" of moving every single node from Stack `a` to its correct target position in Stack `b`. It calculates the required rotations (`ra`, `rra`, `rb`, `rrb`) and capitalizes on simultaneous combo moves (`rr`, `rrr`) to minimize operations. It always moves the strictly "cheapest" node. Once three elements remain in `a`, they are sorted using a hardcoded `sort_three`. Finally, elements are pushed back from `b` to `a` into their precise target slots.
- **Justification:** The Turk algorithm is incredibly powerful for highly disordered stacks. By greedily calculating the cheapest move dynamically at every step, it minimizes the operation count brilliantly, easily meeting the rigorous $\mathcal{O}(n \log n)$ operation limits required for large, chaotic datasets.

---

## ⏱️ Performance Benchmark

The project includes a `--bench` flag that outputs detailed analytics after sorting. Based on the 42 curriculum standards, the algorithms consistently hit the following metrics:

- **For 100 random numbers:** $< 700$ operations *(Excellent Performance)*
- **For 500 random numbers:** $< 5500$ operations *(Excellent Performance)*

---

## 🚀 Instructions

### Compilation
A standard `Makefile` is provided. Run the following commands from the root directory:
- `make` : Compiles the `push_swap` binary.
- `make bonus` : Compiles the `checker` binary.
- `make clean` : Removes object files.
- `make fclean` : Removes object files and binaries.
- `make re` : Recompiles the project from scratch.

### Execution
Run the program with a list of integers (the first argument is the top of the stack):
```bash
./push_swap 4 67 3 87 23
```

You can optionally force a specific algorithm or view the detailed performance benchmark metrics:
```bash
# Force adaptive behavior (default)
./push_swap --adaptive 4 67 3 87 23

# Display performance metrics to stderr
./push_swap --bench 4 67 3 87 23
```

To test the accuracy with the bonus checker:
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

---

## 🤖 Resources and AI Usage

- **References:** General understanding of sorting algorithms (Selection Sort, algorithmic complexity) from standard computer science literature. The "Turk Algorithm" concept popularized within the 42 network for optimal `push_swap` performance.
- **AI Usage:** Artificial Intelligence was used as a learning and debugging support tool throughout the development of this project. Specifically, it was used to understand complex theoretical concepts behind the sorting algorithms (such as cost calculation in the Turk algorithm and chunk partitioning strategies), to help analyze specific parts of the code, and to assist in identifying complex bugs that were difficult to trace manually. All code was written and understood by the authors themselves.