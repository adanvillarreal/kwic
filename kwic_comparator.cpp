class AscendingComparator : public kwic_comparator {
  public:
    bool compare(string a, string b) {
        return a < b
    }
}
