bool winnerOfGame(const char *restrict colors) {
    const size_t len = strlen(colors);
    if (len <= 2) { return false; }

    size_t a = 0;
    size_t b = 0;

    for (size_t i = 1; i < len - 1; i += 1) {
        if (colors[i - 1] == colors[i] && colors[i] == colors[i + 1]) {
            switch (colors[i]) {
                case 'A':
                    a += 1;
                    break;
                case 'B':
                    b += 1;
                    break;
                default:
                    perror("invalid input");
                    exit(1);
            }
        }
    }

    return a > b;
}
