	#include <iostream>
	#include <algorithm>
	#include <iterator>
	#include <fstream>
	#include <iomanip>
	using namespace std;
	
	float arr[700000];
	
	//void myMerge(char nameFile[10], int n)
	//{
	//    ifstream in;
	//    in.open(nameFile);
	//
	//    float x = 0;
	//    in.read(reinterpret_cast<char*>(&x), sizeof(float));
	//    int i = 0;
	//    while (i < n) {
	//        if (arr[i] < x) {
	//            printf("%0.2f ", arr[i++]);
	//        }
	//        else {
	//            printf("%0.2f ", x);
	//            if (!in.read(reinterpret_cast<char*>(&x), sizeof(float))) {
	//                break;
	//            }
	//        }
	//    }
	//
	//    if (i < n) {
	//        while (i < n) {
	//            printf("%0.2f ", arr[i++]);
	//        }
	//    }
	//    else {
	//        do {
	//            printf("%0.2f ", x);
	//        } while (in.read(reinterpret_cast<char*>(&x), sizeof(float)));
	//    }
	//
	//    in.close();
	//}
	
	int main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(0);
	    char nameFile[10] = "input.txt";
	    int n; cin >> n;
	    // first half  : save to file 
	    int size1 = 0;
	   	if(n>500000){
	   		size1 = n - 500000;	
		}
	   	for (int k = 0; k < size1; cin >> arr[k++]);
	   	sort(arr,arr+size1);
	   	
	  	ofstream ofs(nameFile);
	   	copy(arr, arr + size1, ostream_iterator<float>(ofs, " "));
	    ofs.close();
	    	
	    // second half
	    int size2 = n - size1;
	    for (int k = 0; k < size2; cin >> arr[k++]);
	    sort(arr,arr+size2);
	    
	   	 // merge
	   	ifstream ifs(nameFile); // re-open first half
	    cout << fixed << setprecision(2);
	    merge(istream_iterator<float>(ifs), istream_iterator<float>(),
	          arr, arr + size2, ostream_iterator<float>(cout, " "));
	    ifs.close();      
	          
	    return 0;
	}
