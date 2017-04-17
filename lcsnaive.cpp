#include <iostream>
#include <string>
#include <ctime>


using namespace std;

class LCS
{
    public:
        int lcs_length_cal( string, string,int,int ) ;
        timespec diff( timespec start, timespec end );

        void lcs_processing();
};
int call_count=0;
int LCS :: lcs_length_cal( string A, string B,int a,int b )
{
    call_count++;
    if (a==0||b==0)
    {
        return 0;
    } 

    else if (A[a-1]==B[b-1])
    {
        return lcs_length_cal(A,B,a-1,b-1)+1;
    }
    else
    {
        return max(lcs_length_cal(A,B,a-1,b),lcs_length_cal(A,B,a,b-1));
    }


    
}

timespec LCS :: diff( timespec start, timespec end )
{
    timespec temp ;
    if ( ( end.tv_nsec - start.tv_nsec ) < 0 )
    {
        temp.tv_sec = end.tv_sec - start.tv_sec - 1 ;
        temp.tv_nsec = 1000000000 + end.tv_nsec - start.tv_nsec ;
    }
    else
    {
        temp.tv_sec = end.tv_sec - start.tv_sec ;
        temp.tv_nsec = end.tv_nsec - start.tv_nsec ;
    }
    return temp ;
}
void LCS :: lcs_processing()
{
    string a="GAACGCCTTCAAGCCAATTAT";
    string b= "GTTTCGATCGAGGAATTATGA";
    int k=a.length();
    int kk=b.length();
    struct timespec ts, te;
    clock_gettime( CLOCK_PROCESS_CPUTIME_ID , &ts );
    int kkk=lcs_length_cal(a,b,k,kk);
    clock_gettime( CLOCK_PROCESS_CPUTIME_ID , &te );
    cout << "time taken " << diff( ts, te ).tv_sec << ":" << diff( ts, te ).tv_nsec << endl ;
    cout<<"length of LCS is "<<kkk;
}

int main()
{
    LCS l ;
    l.lcs_processing(); 
    cout<<endl;
    //cout<<"number of recursive call "<<call_count-1<<endl;
    return 0; 
}
