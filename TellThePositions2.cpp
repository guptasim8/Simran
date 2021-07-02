/*
In a class there are ‘n’ number of students. They have three different subjects: Data Structures, Algorithm Design & Analysis and Operating Systems. 
Marks for each subject of all the students are provided to you. You have to tell the position of each student in the class. 
Print the names of each student according to their position in class. Tie is broken on the basis of their roll numbers. 
Note: Between two students having same marks, the one with less roll number will have higher rank. The input is provided in order of roll number.

Input Format:
First line will have a single integer ‘n’, denoting the number of students in the class.
Next ‘n’ lines each will have one string denoting the name of student and three space separated integers m1, m2, m3 denoting the marks in three subjects.

Output Format:
Print ‘n’ lines having two values: First, the position of student in the class and second his name.

Constraints:
1 <= n <= 10^4
0 <= m1, m2, m3 <= 100

Sample Input:
3
Mohit 94 85 97
Shubham 93 91 94
Rishabh 95 81 99

Sample Output:
1 Shubham
2 Mohit
3 Rishabh
*/

//Code in C++ -> O(n2)
#include<bits/stdc++.h>
using namespace std;
struct student{
    string name;
    int m1,m2,m3;
    int total;
    int rollno;
};
//sorting comparator(if true (a,b) else (b,a)
bool compareTwoStudents(student a, student b)
{
    // returns true if a.total>b.total or 
    if (a.total != b.total)
        return a.total > b.total;
     
    // if a.total==b.total then a.rollno<b.rollno
    return (a.rollno < b.rollno);
}
int main()
{
    int n;
    cin>>n;
    student *s=new student[n];
    
    for(int i=0;i<n;i++){
        cin>>s[i].name>>s[i].m1>>s[i].m2>>s[i].m3;
        s[i].total=s[i].m1+s[i].m2+s[i].m3;
        s[i].rollno=i+1;
    }
    if(n==1)
    {   
        cout<<s[0].name<<endl;
        return 0;
    }
  // sorting using default sort method of C++ library and user defined comparator
    sort(s, s + n, compareTwoStudents);
    
    for(int i=0;i<n;i++){
        cout<<i+1<<" "<<s[i].name<<endl;
    }
	return 0;
}
