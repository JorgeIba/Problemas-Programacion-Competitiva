#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli t=0;

vector<lli> numeros;
lli CeilIndex( vector<lli> tailIndex, lli buscar, lli r)
{
	lli l=0;
	lli res=0;
	while(l<=r)
	{
		lli posible = l + (r-l)/2;
		if ( buscar <= numeros[ tailIndex[posible] ]  )
		{
			res = posible;
			r = posible-1;
		}
		else
		{
			l = posible + 1;
		}	
	}
	
	return res;
}

void LIS(lli n)
{
	vector<lli> tailIndex(n,0);
	vector<lli> prevIndex(n,-1);
	
	lli ultimo=0;
	
	for (int i=1; i<n; i++)
	{
		if (numeros[i] <= numeros[tailIndex[0]])
		{
			tailIndex[0] = i;
		}
		else if (numeros[i] >= numeros[tailIndex[ultimo]])
		{
			prevIndex[i] = tailIndex[ultimo];
			ultimo++;
			tailIndex[ultimo] = i;
			
		}
		else
		{
			lli index = CeilIndex( tailIndex, numeros[i], ultimo);
			prevIndex[i] = tailIndex[index-1];
			tailIndex[index] = i;
		}
	}
	
	stack<lli> pila;
	lli x=tailIndex[ultimo];
	cout<<"Max hits: "<<(lli)(ultimo+1)<<endl;
	while(x!=-1)
	{
		pila.push(numeros[x]);
		x = prevIndex[x];
	}	
	while(!pila.empty())
	{
		cout<<pila.top()<<endl;
		pila.pop();
	}	
}



void funcion1(int indice)
{
	numeros.resize(0);
	string TAux;
	while(getline(cin,TAux)and(!TAux.empty()))
	{
			lli x= atoi(TAux.c_str());
			numeros.push_back(x);
	}
	LIS(numeros.size());
	if (indice!=t-1)
	{
		cout<<endl;
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	string aux;
	getline(cin, aux);
	getline(cin, aux);
	for (lli i=0; i<t; i++)
	{
		funcion1(i);
	}
	return 0;
}
