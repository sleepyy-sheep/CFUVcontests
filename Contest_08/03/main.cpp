int* new_array(int len, int value) {
    int* arr = new int[len];
    for (int i = 0; i < len; i++) {
        arr[i] = value;
    }
    return arr;
}
int set_new_length(int** array, int old_len, int new_len) {
    int* new_arr = new int[new_len];
    if (new_len < old_len) {
        for (int i = 0; i < new_len; i++) {
            new_arr[i] = (*array)[i];
        }
    } else if (new_len > old_len) {
        for (int i = 0; i < old_len; i++) {
            new_arr[i] = (*array)[i];
        }
    }
    delete[] *array;
    *array = new_arr;
    return new_len;
}
int merge(int** dest_array, int len_dest_array, const int* src_array, int len_src_array) {
    int total_len = len_dest_array + len_src_array;
    int* new_arr = new int[total_len];
    int i = 0;
    for (; i < len_dest_array; i++) {
        new_arr[i] = (*dest_array)[i];
    }
    int k = 0;
    for (; i < total_len; i++) {
        new_arr[i] = src_array[k];
        k++;
    }
    delete[] *dest_array;
    *dest_array = new_arr;
    return total_len;
}
int dot(const int* a, const int* b, int len) {
    int res = 0;
    for (int i = 0; i < len; i++) {
        res += a[i] * b[i];
    }
    return res;
}
int* find(int* array, int len, int value) {
    for (int i = 0; i < len; i++) {
        if (array[i] == value) {
            return &array[i];
        }
    }
    return nullptr;
}
void delete_array(int** array) {
    if (*array == nullptr) {
        return;
    }
    delete[] *array;
    *array = nullptr;
}
