#!/bin/bash
# Tests des cas limites de ScalarConverter (ex00)
# Usage : ./test.sh [binaire]   (par défaut ./exec)

BIN=${1:-./exec}

if [ ! -x "$BIN" ]; then
	echo "Binaire $BIN introuvable, lance make d'abord."
	exit 1
fi

BOLD="\033[1m"
CYAN="\033[36m"
YELLOW="\033[33m"
RESET="\033[0m"

section() {
	echo
	echo -e "${BOLD}${CYAN}========== $1 ==========${RESET}"
}

# run <attendu> <argument>
run() {
	echo
	echo -e "${YELLOW}\$ $BIN [$2]${RESET}   -> attendu : $1"
	"$BIN" "$2"
}

# ---------------------------------------------------------------------------
section "Nombre d'arguments"
echo -e "${YELLOW}\$ $BIN${RESET}   -> attendu : erreur (argc != 2)"
"$BIN"
echo -e "${YELLOW}\$ $BIN 4 2${RESET}   -> attendu : erreur (argc != 2)"
"$BIN" 4 2

# ---------------------------------------------------------------------------
section "Valides : exemples du sujet"
run "Non displayable / 0 / 0.0f / 0.0" "0"
run "impossible / impossible / nanf / nan" "nan"
run "'*' / 42 / 42.0f / 42.0" "42.0f"

# ---------------------------------------------------------------------------
section "Valides : char"
run "'a' / 97 / 97.0f / 97.0" "'a'"
run "'0' / 48 / 48.0f / 48.0" "'0'"
run "' ' / 32 / 32.0f / 32.0" "' '"
run "''' / 39 / 39.0f / 39.0" "'''"

# ---------------------------------------------------------------------------
section "Valides : int"
run "'*' / 42 / 42.0f / 42.0" "42"
run "Non displayable / -42 / -42.0f / -42.0" "-42"
run "'*' / 42 / 42.0f / 42.0" "+42"
run "Non displayable / 127 / 127.0f / 127.0" "127"
run "impossible / 128 / 128.0f / 128.0" "128"
run "impossible / 2147483647 / 2147483648.0f (arrondi float) / 2147483647.0" "2147483647"
run "impossible / -2147483648 / -2147483648.0f / -2147483648.0" "-2147483648"

# ---------------------------------------------------------------------------
section "Valides : int qui déborde (pas une erreur de syntaxe)"
run "impossible partout (ou float/double affichés)" "2147483648"
run "impossible partout (ou float/double affichés)" "-2147483649"
run "impossible partout (ou float/double affichés)" "99999999999"

# ---------------------------------------------------------------------------
section "Valides : float"
run "Non displayable / 0 / 0.0f / 0.0" "0.0f"
run "Non displayable / -4 / -4.2f / -4.2" "-4.2f"
run "Non displayable / 4 / 4.2f / 4.2" "4.2f"
run "Non displayable / 0 / -0.0f / -0.0" "-0.0f"
run "impossible / impossible / nanf / nan" "nanf"
run "impossible / impossible / +inff / +inf" "+inff"
run "impossible / impossible / -inff / -inf" "-inff"

# ---------------------------------------------------------------------------
section "Valides : double"
run "Non displayable / 0 / 0.0f / 0.0" "0.0"
run "Non displayable / -4 / -4.2f / -4.2" "-4.2"
run "Non displayable / 0 / 0.1f / 0.1 (précision ?)" "0.1"
run "impossible / impossible / +inff / +inf" "+inf"
run "impossible / impossible / -inff / -inf" "-inf"
run "impossible / impossible / impossible (float déborde) / valeur du double" "1000000000000000000000000000000000000000.0"

# ---------------------------------------------------------------------------
section "Invalides : vide / pas de chiffre"
run "erreur" ""
run "erreur" " "
run "erreur" "abc"
run "erreur" "-"
run "erreur" "+"
run "erreur" "."
run "erreur" "f"

# ---------------------------------------------------------------------------
section "Invalides : char mal formé"
run "erreur" "'ab'"
run "erreur" "''"
run "erreur" "'a"
run "erreur" "a'"
run "débattu : erreur ou 'a'" "a"

# ---------------------------------------------------------------------------
section "Invalides : caractères en trop"
run "erreur" "42abc"
run "erreur" "42 "
run "erreur" " 42"
run "erreur" "12-3"
run "erreur" "--42"
run "erreur" "+-42"

# ---------------------------------------------------------------------------
section "Invalides : point mal placé"
run "erreur" "1.2.3"
run "débattu : erreur (forme courante)" "42."
run "débattu : erreur (forme courante)" ".42"
run "erreur" "42.f"
run "erreur" ".f"

# ---------------------------------------------------------------------------
section "Invalides : suffixe f incorrect"
run "erreur" "42f"
run "erreur" "4.2ff"
run "erreur" "4.2F"
run "erreur" "4f.2"

# ---------------------------------------------------------------------------
section "Invalides : notations hors sujet"
run "erreur" "0x2A"
run "erreur" "1e10"
run "erreur" "42L"
run "erreur" "42u"

# ---------------------------------------------------------------------------
section "Invalides : pseudo-littéraux mal écrits"
run "débattu : erreur (sujet = +inff/-inff)" "inff"
run "débattu : erreur (sujet = +inf/-inf)" "inf"
run "erreur" "NaN"
run "erreur" "nanff"
run "erreur" "-nan"
run "erreur" "+nanf"
