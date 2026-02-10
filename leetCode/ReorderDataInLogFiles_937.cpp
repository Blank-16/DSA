class Solution
{
public:
    vector<string> reorderLogFiles(vector<string> &logs)
    {
        auto cmp = [](const string &a, const string &b)
        {
            // split a
            int i = a.find(' ');
            string idA = a.substr(0, i);
            string contentA = a.substr(i + 1);

            // split b
            int j = b.find(' ');
            string idB = b.substr(0, j);
            string contentB = b.substr(j + 1);

            bool isDigitA = isdigit(contentA[0]);
            bool isDigitB = isdigit(contentB[0]);

            // Rule 1: letter-logs before digit-logs
            if (!isDigitA && isDigitB)
                return true;
            if (isDigitA && !isDigitB)
                return false;

            // Rule 2: both letter-logs
            if (!isDigitA && !isDigitB)
            {
                if (contentA != contentB)
                    return contentA < contentB;
                return idA < idB;
            }

            // Rule 3: both digit-logs → keep original order
            return false;
        };

        stable_sort(logs.begin(), logs.end(), cmp);
        return logs;
    }
};