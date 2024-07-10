#include <bits/stdc++.h>
using namespace std;
string solve(string str)
{
    while (true)
    {
        int p = 0, idx = -1;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '/')
            {
                p == 1;
                idx = i;
                break;
            }
        }

        if (p == 1)
        {
            int ch1 = str[idx - 1] - '0';
            int ch2 = str[idx + 1] - '0';
        }
    }
}
int evaluateArithmeticExpression(string &expression)
{
    stack<char> st;

    int n = expression.length();

    int ans = 0;
    st.push(expression[0]);
    for (int i = 1; i < n; i++)
    {
        if (expression[i] == ')')
        {
            string str = "";
            while (true)
            {
                char ch = st.top();
                st.pop();
                if (ch == '(')
                {
                    break;
                }
                str += ch;
            }

            reverse(str.begin(), str.end());

            string result = solve(str);
        }
        else
        {
            st.push(expression[i]);
        }
    }
}

int32_t main()
{
    string expression = "(3*(5+2)*(10-7))";

    int ans = evaluateArithmeticExpression(expression);

    cout << "Ans: " << ans << endl;
}