#include <bits/stdc++.h>

#define lli long long int
#define endl "\n"
#define debug(n) cout<<n<<endl
#define debug2(a, b) cout<<a<<" "<<b<<endl;
#define forn(i, in, fin) for(int i = in; i<fin; i++)
#define all(v) v.begin(), v.end()
#define fastIO(); ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

struct point{
	lli x, y;
	point(): x(0), y(0){}
	point(lli x, lli y): x(x), y(y){}

	point operator+(const point & p) const{return point(x + p.x, y + p.y);}
	point operator-(const point & p) const{return point(x - p.x, y - p.y);}
	point operator*(const lli & k) const{return point(x * k, y * k);}
	point operator/(const lli & k) const{return point(x / k, y / k);}

	point operator+=(const point & p){*this = *this + p; return *this;}
	point operator-=(const point & p){*this = *this - p; return *this;}
	point operator*=(const lli & p){*this = *this * p; return *this;}
	point operator/=(const lli & p){*this = *this / p; return *this;}



	lli dot(const point & p) const{return x * p.x + y * p.y;}
	lli cross(const point & p) const{return x * p.y - y * p.x;}
};

istream &operator>>(istream &is, point & p){return is >> p.x >> p.y;}
ostream &operator<<(ostream &os, const point & p){return os << "(" << p.x << ", " << p.y << ")";}

bool colineal(point a, point b, point c)
{
    if( (b-a).cross(c-a) == 1  ) return true;
    return false;
}


int main()
{
    fastIO();
    lli n; cin>>n;
    vector<point> puntos(n);
    for(auto &p: puntos)
    {
        cin>>p;
    }

    lli res = (n-2)*(n-1)*n / 6;
    map< tuple<lli,lli,lli>, set< pair<lli,lli> > > rectas;
    for(int i = 0; i<n; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            lli x1 = puntos[i].x, x2 = puntos[j].x, y1 = puntos[i].y, y2 = puntos[j].y;
            lli a = y2-y1, b = x1 - x2, c = x1*y2 - x2*y1;
            if(a < 0 || (a==0 && b < 0))
            {
                a = -a, b = -b, c = -c;
            }
            lli gcd = __gcd(a,abs(b));
            gcd = __gcd(gcd, abs(c));
            a/=gcd, b/=gcd, c/=gcd;
            rectas[{a,b,c}].insert({x1,y1});
            rectas[{a,b,c}].insert({x2, y2});
        }
    }

    for(auto x: rectas)
    {
        lli t = x.second.size();
        res -= ((t-2)*(t-1)*t)/6;
    }
    cout<<res<<endl;

    return 0;
}
