#include <vector>
#include <string>
#include <algorithm>

namespace algorithms
{
    namespace string
    {
        int Prefix(std::string s, int pos)
        {
            int i = 0;
            int res = 0;
            while (s[i] == s[pos])
            {
                ++pos;
                ++i;
                ++res;
            }
            return res;
        }

        std::vector<int> Zfunction(std::string s)
        {
            int l = 0;
            int r = 0;
            std::vector<int> z(s.size(), 0);

            for (int i = 1; i < s.size(); ++i)
            {
                if (i > r)
                {
                    z[i] = Prefix(s, i);
                    if (z[i] > 0)
                    {
                        l = i;
                        r = i + z[i] - 1;
                    }
                }
                else
                {
                    z[i] = std::min(z[i - l], r - i + 1);
                    z[i] += Prefix(s, i);
                }
            }
            return z;
        }
    }
}



