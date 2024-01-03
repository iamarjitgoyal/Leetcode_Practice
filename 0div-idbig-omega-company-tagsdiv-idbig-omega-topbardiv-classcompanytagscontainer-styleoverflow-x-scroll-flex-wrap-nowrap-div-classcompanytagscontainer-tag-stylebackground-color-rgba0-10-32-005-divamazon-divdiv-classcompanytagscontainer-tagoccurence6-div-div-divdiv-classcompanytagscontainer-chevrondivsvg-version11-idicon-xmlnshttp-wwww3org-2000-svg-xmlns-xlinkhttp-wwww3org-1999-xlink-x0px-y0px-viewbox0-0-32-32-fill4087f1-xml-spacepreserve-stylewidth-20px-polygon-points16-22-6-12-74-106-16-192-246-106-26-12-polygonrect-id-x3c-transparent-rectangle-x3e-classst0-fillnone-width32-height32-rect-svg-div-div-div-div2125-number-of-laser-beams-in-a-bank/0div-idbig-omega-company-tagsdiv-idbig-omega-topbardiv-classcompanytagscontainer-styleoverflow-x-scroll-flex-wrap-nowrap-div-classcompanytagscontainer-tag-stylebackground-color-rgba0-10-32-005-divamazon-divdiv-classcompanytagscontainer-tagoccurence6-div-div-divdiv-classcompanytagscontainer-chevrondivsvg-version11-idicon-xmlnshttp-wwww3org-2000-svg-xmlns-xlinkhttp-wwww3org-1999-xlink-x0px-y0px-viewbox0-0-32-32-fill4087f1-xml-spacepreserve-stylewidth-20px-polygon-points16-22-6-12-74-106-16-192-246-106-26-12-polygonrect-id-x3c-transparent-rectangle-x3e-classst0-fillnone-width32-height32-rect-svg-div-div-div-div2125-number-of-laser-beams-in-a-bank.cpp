class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int previousRowCount = 0;
        int totalBeams = 0;

        for (const string& row : bank) {
            int currentRowCount = calculateSecurityDevices(row);
            if (currentRowCount == 0)
                continue;

            totalBeams += currentRowCount * previousRowCount;
            previousRowCount = currentRowCount;
        }
        return totalBeams;
    }

private:
    int calculateSecurityDevices(const string& s) {
        int count = 0;
        for (char c : s)
            count += c - '0';

        return count;
    }
};
