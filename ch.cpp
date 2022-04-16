#include <bits/stdc++.h>
using namespace std;
typedef struct hands
{
    int id;
    int f = 1;

} hand;
int im1 = 0;
int im2 = 0;
hand p1_l;
hand p2_l;
hand p1_r;
hand p2_r;
void display_hand(int id)
{
    printf("\nplayer%i status:\n", id);
    printf("lh\trh\n");
    if (id == 1)
        printf("%i\t%i", p1_l.f, p1_r.f);
    else if (id == 2)
        printf("%i\t%i\n", p2_l.f, p2_r.f);
}
void score_calc(string s, int id)
{
    if (id == 1)
    {
        if (s == "lr")
        {
            p2_r.f = (p2_r.f + p1_l.f) % 5;
            if (p1_l.f == 0)
            {
                im1++;
                cout << "ILLEGAL MOVE: You WILL BE DISQUALIFIED IN " << 3 - im1 << "illegal moves";
            }
        }
        else if (s == "ll")
        {
            p2_l.f = (p2_l.f + p1_l.f) % 5;
            if (p1_l.f == 0)
            {
                im1++;
                cout << "ILLEGAL MOVE: You WILL BE DISQUALIFIED IN " << 3 - im1 << "illegal moves";
            }
        }
        else if (s == "rl")
        {
            p2_l.f = (p2_l.f + p1_r.f) % 5;
            if (p1_r.f == 0)
            {
                im1++;
                cout << "ILLEGAL MOVE: You WILL BE DISQUALIFIED IN " << 3 - im1 << "illegal moves";
            }
        }
        else if (s == "rr")
        {
            p2_r.f = (p2_r.f + p1_r.f) % 5;
            if (p1_r.f == 0)
            {
                im1++;
                cout << "ILLEGAL MOVE: You WILL BE DISQUALIFIED IN " << 3 - im1 << "illegal moves";
            }
        }
        else if (s[0] = 'r' && s[1] == 'd')
        {
            int k = s[2] - 48;
            if (k > (p1_l.f + p1_r.f) ||( k == p1_l.f||k==p1_r.f))
            {
                im1++;
                cout << "ILLEGAL MOVE: You WILL BE DISQUALIFIED IN " << 3 - im1 << "illegal moves";
                return;
            }
            int w = p1_l.f + p2_l.f;
            p1_l.f = k;
            p1_r.f = (w - k) % 5;
        }
    }
    if (id == 2)
    {
        if (s == "lr")
        {
            p1_r.f = (p2_l.f + p1_r.f) % 5;
            if (p2_l.f == 0)
            {
                im2++;
                cout << "ILLEGAL MOVE: You WILL BE DISQUALIFIED IN " << 3 - im2 << " illegal moves";
            }
        }
        else if (s == "ll")
        {
            p1_l.f = (p2_l.f + p1_l.f) % 5;
            if (p2_l.f == 0)
            {
                im1++;
                cout << "ILLEGAL MOVE: You WILL BE DISQUALIFIED IN " << 3 - im2 << " illegal moves";
            }
        }
        else if (s == "rl")
        {
            p1_l.f = (p2_r.f + p1_l.f) % 5;
            if (p2_r.f == 0)
            {
                im2++;
                cout << "ILLEGAL MOVE: You WILL BE DISQUALIFIED IN " << 3 - im2 << " illegal moves";
            }
        }
        else if (s == "rr")
        {
            p1_r.f = (p2_r.f + p1_r.f) % 5;
            if (p2_r.f == 0)
            {
                im2++;
                cout << "ILLEGAL MOVE: You WILL BE DISQUALIFIED IN " << 3 - im2 << " illegal moves";
            }
        }
        else if (s[0] = 'r' && s[1] == 'd')
        {
            int k = s[2] - 48;
            if (k > (p2_l.f + p2_r.f) || (k == p2_l.f||k==p2_r.f))
            {
                im2++;
                cout << "ILLEGAL MOVE: You WILL BE DISQUALIFIED IN " << 3 - im2 << " illegal moves";
                return;
            }
            int w = p2_l.f + p2_r.f;
            p2_l.f = k;
            p2_r.f = (w - k) % 5;
        }
    }
}

int main()
{
    p1_l.id = p1_r.id = 1;
    p2_l.id = p2_r.id = 2;
    while (((p1_l.f != 0 || p1_r.f != 0) && (p2_l.f != 0 || p2_r.f != 0)))
    {
        display_hand(1);
        display_hand(2);
        cout << "Move P1:";
        string s1;
        cin >> s1;
        score_calc(s1, 1);
        if(im1>=3)
        {
            cout << "P2 WINS!!!";
            display_hand(1);
            display_hand(2);
            return 0;
        }
        if (im2 >= 3 || (p2_l.f == 0 && p2_r.f == 0))
        {
            cout << "P1 WINS!!!";
            display_hand(1);
            display_hand(2);

            return 0;
        }
        display_hand(1);
        display_hand(2);
        cout << "Move P2:";
        string s2;
        cin >> s2;
        score_calc(s2, 2);
        if(im2>=3)
        {
            cout << "P1 WINS!!!";
            display_hand(1);
            display_hand(2);

            return 0;
        }
        if (im1 >= 3 || (p1_l.f == 0 && p1_r.f == 0))
        {
            cout << "P2 WINS!!!";
            display_hand(1);
            display_hand(2);
            return 0;
        }
    }
}
