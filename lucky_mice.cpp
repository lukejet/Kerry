
#include <string>
#include <iostream>
#include <vector>
#include <cmath>

#define  NS 32

int v = 0;

inline int isAlive(std::vector<unsigned int>& a, long n)
{
	return a[n/NS]&(1<<(n%NS));
}
inline void Kill(std::vector<unsigned int>& a, long n)
{
	a[n/NS] &= ~(1<<(n%NS));
}

int fooN(long n, int m)
{
	if (m<1)
		return 0;
	if (m== 1)
		return n;
	if (n<1)
		return 0;
	if (n== 1)
		return 1;
	int k = 0;
	int lm = n%NS;
	int ln = n/NS;
	lm>0 ? ln++ : 0 ;
	std::vector<unsigned int> aa(ln);  // sizeof int == 4
	long i=0, kills=0;
	for(auto& ee : aa)
	{
		ee = 0xFFFFFFFF;
	}
	
	i=0;
	while(1)
	{
		k = m-1;
		while(k--)
		{
			i = (++i<n) ? i : 0;
			while (!isAlive(aa, i))
				i = (++i<n) ? i : 0;
		}
		
	//	aa[i/NS] &= ~(1<<(i%NS));
		Kill(aa, i);
		kills++;
		if (v == 1)
			std::cout << "No."<< i+1 << " killed, and total "<< kills << " mouses killed." <<std::endl;
		if (kills == (n-1))
			break;
		i = (++i<n) ? i : 0;
		while (!isAlive(aa, i))
			i = (++i<n) ? i : 0;
			
	}
	
	i=0;
	while(!isAlive(aa,i)) i++;
	return i+1;
}

// parament: n input the numbers of total, m is the eat number for each.
// return: the lucky one id number.
template <typename T>
int fooNT(long n, int m)
{
	if (n < 1 ||  m<1)
		return 0;
	if (m== 1)
		return n;
	if (n== 1)
		return 1;
	int k = 0;
	int ns = sizeof(T)*8;
	long i=0, kills=0;
	
	int lm = n%ns;
	int ln = n/ns;
	lm>0 ? ln++ : 0 ;
	
	std::vector<T> aa(ln);
	unsigned long kk = pow(2, ns)-1;
	for(auto& ee: aa)
	{
		ee = kk;
	}
	i=0;
	while(1)
	{
		k = m-1;
		while(k--)
		{
			i = (++i<n) ? i : 0;
			while(!isAlive(aa, i))
				i = (++i<n) ? i : 0;
		}
		
		Kill(aa, i);
		kills++;
		//std::cout << "No."<< i << " killed, and total "<< kills << " mouses killed." <<std::endl;
		if (kills == (n-1))
			break;
		i = (++i<n) ? i : 0;
		while (!isAlive(aa, i))
			i = (++i<n) ? i : 0;
			
	}
	
	i=0;
	while(!isAlive(aa, i)) i++;
	return i+1;
}

int main(int argc, char* argv[])
{
	long m=0, n=0;
	if (argc == 2)
		v = 1;

	std::cout << sizeof (int) <<std::endl;
	std::cout << sizeof (long) <<std::endl;

	//std::cout << ~(1<<5) <<std::endl;

	while (1) {
		m=n=0;
		std::cout << "Input the number of mouses: " ;
		std::cin >> n;
		std::cout << "Input the number of mouse will be killed: " ;
		std::cin >> m;
		//if (isnumber(m))
		//	continue;
		if (m<=0)
			break;
//		if (m > n)
//		{
//			std::cout<< "the number will be killed must not bigger than the total number of mouses"<<std::endl;
//			continue;
//		}
		std::cout << n << ":" << m << std::endl;
		int luky = fooN(n,m);
		std::cout << "the lucky mouse is No." << luky << std::endl<< std::endl;
		std::vector<int> vi(n);
/*		int luck = 0;
		while (m < n)
		{
			luck = fooN(n, m);
			std::cout << m <<"\t:\t" << luck <<std::endl<< std::endl;
			vi[luck] ++;
			m++;
		}
		for(int i=0; i<m; i++)
		{
			if (vi[i]>4)
				std::cout << i << ":\t" << vi[i] <<std::endl;
			
		}
		
*/		
	}
	return 0;
}


