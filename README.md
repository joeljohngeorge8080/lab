# Compiler Design Lab

Experiments 02–07 and 12. Each experiment is in its own directory.

## Requirements

- `gcc`
- `flex` (provides `lex`)
- `bison` (provides `yacc`)

On Debian/Ubuntu: `sudo apt install gcc flex bison`

## Lex/YACC programs

Experiments 03, 04 and 05 use both LEX and YACC. Run these commands inside the experiment's directory:

```
lex arithmetic.l
yacc -d arithmetic.y
gcc lex.yy.c y.tab.c -ll
./a.out
```

Replace the file names for each experiment:

| Directory | LEX file | YACC file |
|---|---|---|
| `exp03` | `arithmetic.l` | `arithmetic.y` |
| `exp04` | `identifier.l` | `identifier.y` |
| `exp05` | `calc.l` | `calc.y` |

Experiment 02 uses LEX only, so it has no YACC step:

```
cd exp02
lex lex1.l
gcc lex.yy.c -ll
./a.out
```

Type input and press Enter, or pipe it in, for example `echo "2+3*4" | ./a.out`. Input must end with a newline.

### Examples

- **exp02** (tokenizer): `int x = 3.14 + a1;` prints one token per line, such as `int : Keyword`.
- **exp03** (arithmetic): `a+b*(c-2)` → `Valid Expression`; `(a+b` → `Invalid Expression`.
- **exp04** (identifier): `ab1` → `Valid Identifier`; `1ab` → `Invalid Identifier`.
- **exp05** (calculator): `(2+3)*4` → `Result: 20` then `Valid Expression`. Division or modulo by zero is not checked, so it stops with a floating point exception.

## C programs

Experiments 06, 07 and 12 are plain C. Compile and run each one with:

```
gcc file.c -o name
./name
```

### exp06 (epsilon closure)

```
cd exp06
gcc etrans.c -o exp06
./exp06
```

Input: the number of alphabets, the alphabet symbols (use `e` for epsilon), the number of states, the number of transitions, then one `source symbol destination` line per transition. For example:

```
2
a e
3
2
1 e 2
2 e 3
```

Output: the epsilon closure of each state. For this input, q1's closure is `{q1 q2 q3}`.

### exp07 (recursive-descent parser)

```
cd exp07
gcc recursive.c -o exp07
./exp07
```

Type an expression and press Enter. It prints `Accepted` or `Rejected`. Spaces are ignored. The grammar is `E -> T ('+' T)*`, `T -> F ('*' F)*`, `F -> 'a' | '(' E ')'`.

### exp12 (code generator)

```
cd exp12
gcc backend.c -o exp12
./exp12
```

Type one three-address statement per line, such as `a=b+c`, then type `exit`. For example, `a=b+c` produces:

```
MOV b,R0
ADD c,R0
MOV R0,a
```
