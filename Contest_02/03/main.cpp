bool compare(std::string a, std::string b) {
    int a_count = 0;
    int b_count = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == '1') a_count += 1;
    }
    for (int i = 0; i < b.length(); i++) {
        if (b[i] == '1') b_count += 1;
    }

    if (a_count != b_count) {
        return a_count > b_count;
    } else {
        return std::stoi(a) < std::stoi(b);
    }
}
