#include <iostream>
#include <stdio.h>
#include <time.h>
#include <ctime>
#include <vector>
#include <omp.h>
#define MAXN 100005
using namespace std;


bool check_point(pair <double, double> Center, double R, pair <double, double> Point) {
    double Len = (Center.first - Point.first) * (Center.first - Point.first) + (Center.second - Point.second) * (Center.second - Point.second);
    Len *= Len;
    return (Len < R);

}
int main()
{
    pair <double, double> Center;
    double R;
    int n;
    bool ans = 1;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    cin >> Center.first >> Center.second;
    cin >> R;
    cin >> n;

    double Start, Finish, Duration;
    Start = clock();
    #pragma omp parallel
    for(int i = 0; i < n ; i++)
    {
        double X, Y;
        cin>>X>>Y;

        ans = ans * check_point(Center, R, make_pair(X,Y));
    }
    Finish = clock();
    Duration = (Finish - Start) / double(CLOCKS_PER_SEC);
    if (ans)
        cout << "This poligon is inside Circle\n";
    else
        cout << "This poligon is not inside Circle\n";
    cout << Duration << endl;
    return 0;
}
