#include <iostream>
#include <string>

using namespace std;



class LCS
{
public:
	int algoB(int m,int n,string A, string B, int LL[]);
	string algoC(int m,int n,string A,string B, string C);
	void lcs_processing();
};

int LCS::algoB(int m,int n,string A,string B,int LL[])
{
	int i,j;
	int K[2][n+1]={0};
	for (j=0;j<(n+1);j++)
	{
		K[1][j]=0;
	}
	for (i=1;i<=m;i++)
	{
		for (j=0;j<(n+1);j++)
		{
			K[0][j]=K[1][j];
		}
		for (j=1;j<(n+1);j++)
		{
			if (A[i-1]==B[j-1])
				K[1][j]=K[0][j-1]+1;
			else
				K[1][j]=max(K[1][j-1],K[0][j]);
		}
	}
	for (j=0;j<(n+1);j++)
	{
		LL[j]=K[1][j];
	}
	return LL[n];

}

string LCS:: algoC(int m,int n,string A, string B, string C)
{
	string lcs;
	if (m==0)
	{
		lcs="";
		return lcs;

	}
	if (m==1)
	{
		int found;
		found=B.find_first_of(A[0]);
		if (found!=string::npos)
			{
				lcs=A[0];
				return lcs;
			}
		else
			
			{
				lcs="";
		        return lcs;
		    }

		

	}
	int ll1[n+1],ll2[n+1];
	int i=m/2;
	algoB(i,n,A.substr(0,i),B,ll1);

	string rev_A, rev_B;
	string::reverse_iterator rit;
	for (rit=A.rbegin();rit<A.rend();rit++)
		rev_A.push_back(*rit);
	for (rit=B.rbegin();rit<B.rend();rit++)
		rev_B.push_back(*rit);

	algoB(m-i,n,rev_A.substr(0,m-i),rev_B,ll2);
    int max=0;
    int k=0;
	for (int j=0;j<(n+1);j++)
	{
		if (ll1[j]+ll2[n-j]>max)
		{
			max=ll1[j]+ll2[n-j];
			k=j;
		}

	}

	string C1,C2;

	return algoC( i, k, A.substr( 0, i ), B.substr( 0, k ), C1 )+ algoC( m - i , n - k , A.substr( i, m ), B.substr( k, n ), C2 ) ;
}
void LCS :: lcs_processing()
{
    string a="GAACGCCTTCAAGCCAATTATGATTGCTCGCTGCCATGAGAATGGATGTG";
    string b= "AAGGTTTCGATCGAGGGAGAACTATGACGATGACAAAACTACAGCTAATT";
    int k=a.length();
    int kk=b.length();
    int LL[100]={0};
    cout<<"length of LCS is "<<algoB(k,kk,a,b,LL);
    cout<<endl;
    string CC;

    cout<<"string lcs "<<algoC(k,kk,a,b,CC)<<endl;
    cout<<"length of string  "<<(algoC(k,kk,a,b,CC)).length()<<endl;

}

int main()
{

    LCS l;
	l.lcs_processing();
	cout<<endl;

}