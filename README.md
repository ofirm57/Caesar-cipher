# Caesar Cipher in C

This project implements a Caesar cipher in C with support for both text encoding/decoding and automated tests.

---

## 🧠 Program Usage

### 1. Run Unit Tests

To execute built-in unit tests, run the program with the following single argument:

```bash
./ex1 test
```

### 2. Encode or Decode Using Files

To encode or decode text using input/output files, provide **exactly 4 arguments**:

```bash
./ex1 <mode> <shift> <input_file> <output_file> 
```

- `<mode>`: either `encode` or `decode`
- `<shift>`: an integer indicating Caesar shift (positive or negative)
- `<input_file>`: path to a text file with the input string
- `<output_file>`: path to a file where the result will be saved

#### Example:

```bash
./ex1 encode 3 input.txt output.txt 
```

- Encodes the contents of `input.txt` using Caesar cipher with shift `+3`
- Saves the result in `output.txt`

---

## 🔧 Supported Characters

- Only alphabetic characters A–Z and a–z are encoded/decoded
- All other characters remain unchanged
- The cipher preserves letter case (uppercase/lowercase)

---

## 📂 File Summary

- `cipher.c` / `cipher.h` – Caesar cipher logic
- `main.c` – Command-line interface and file handling
- `tests.c` / `tests.h` – Unit tests for encode/decode functions

---

## 👤 Author

Ofir Malkiely


