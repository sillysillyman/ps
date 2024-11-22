# [Silver IV] All about that base - 11086 

[문제 링크](https://www.acmicpc.net/problem/11086) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

구현

### 제출 일자

2024년 11월 22일 19:58:51

### 문제 설명

<p>The base (or radix) of a positional numeral system is the number of symbols that can be used to represent a number in that system. The base 10 system (also known as decimal) uses 10 distinct symbols: 0, 1, . . . , 9. For example, we interpret the number 72345 as:</p>

<p style="text-align:center">7 × 10<sup>4</sup> + 2 × 10<sup>3</sup> + 3 × 10<sup>2</sup> + 4 × 10<sup>1</sup> + 5 × 10<sup>0</sup>.</p>

<p>This example illustrates that in base 10 the symbol at place P ≥ 0 (starting from the right) is multiplied by 10<sup>P</sup> to get its value. More generally, in base B we use B symbols to represent 0, . . . , B − 1, and the symbol at the Pth place is multiplied by B<sup>P</sup> to get its value.</p>

<p>Other bases commonly used in computation include base 2 (or binary, using symbols 0 and 1), base 8 (or octal, using symbols 0–7), and base 16 (or hexadecimal, using symbols 0–9 and a–f). In bases higher than 10, letters represent the higher values. Thus in hexadecimal a–f represent the decimal values 10–15, and in bases ≥ 36 the letter z represents the decimal value 35.</p>

<p>Your job is to determine the bases in which given arithmetic expressions are valid. We define an expression as valid in base B if two conditions are true. First, all the operands used are interpretable in base B as having values in the decimal range [1, 2<sup>32</sup> − 1]. Second, the expression is true. Any arbitrary expression might be valid in zero, one, or more bases. In this problem we will only consider bases 1–36, where base 1 is unary.</p>

<p>Note that following the convention listed above, unary would consist of a single symbol: 0. In this problem, unary numbers use the symbol 1 rather than 0 (think “tally marks”). E.g., 111 in unary is equivalent to the decimal number 3 and 1111111 in unary is equivalent to the decimal number 7</p>

### 입력 

 <p>Input for this problem starts with a line containing an integer 0 ≤ N ≤ 20. The following N lines each contain an arithmetic expression with the following form:</p>

<p style="text-align:center">X op Y = Z</p>

<p>where X, Y , and Z are positive, whole numbers consisting of 1 to 100 symbols from the set 0–9 and a–z, and op is one of the four operators +, -, *, /. For each statement there is at least one base 1 ≤ B ≤ 36 such that X, Y , and Z can all be interpreted in base B as having values in the decimal range [1, 2<sup>32</sup> − 1].</p>

### 출력 

 <p>For each expression, list the bases in which the expression is valid (sorted in ascending base order) or the word “invalid” if the expression not valid in any of the bases 1–36. Use symbols 1–9, then a–z, then 0 to represent bases 1–36 (with the last symbol, 0, representing base 36).</p>

