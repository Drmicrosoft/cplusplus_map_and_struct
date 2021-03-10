#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */


int start_up() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}

// int static r = start_up();

#define endl '\n';


struct l
{
    long long int value;
    l * next = NULL;;
    l * parent = NULL;
    l (int x)
    {
                value = x;
//                parent = NULL:
//                next = NULL:
    }
};
struct r
{
    long long int value ;
    r * next = NULL;
    r * parent = NULL;
    r (int x)
    {
        value = x;
    }
};


struct Node
{
  long long int value ;
  l * left;
  r * right;
  int l_num=0;
  int r_num=0;
  bool init=false;
  bool mid = false;
  l * left_end;
  r * right_end;
}m;




void print()
{
    // cout<<"##############"<<endl;
    // cout<<"print started"<<endl;
    if(m.mid)
    {
        // cout<<"activated m.mid"<<endl;
        // cout<<">>>> " ;
       cout<<m.value<<endl;
        // printf("%.f\n",m.value);
    }
    else {
        auto o = m.right->value + m.left->value;
    //if((abs(m.right->value)%2==1)||(abs(m.left->value)%2==1))
    if(abs(o)%2==1)
    {
        printf("%.1f\n" , o/2.0);
    }
    else {
        printf("%.f\n" , (o/2.0));
    }
    }
    // cout<<"##############"<<endl;
}

inline bool reallocate_left(int x)
{
	cout<<"\n\n\n"<<endl;
	const clock_t begin_time1 = clock();
    if(m.left)
    {
        if(m.left->value<x)
        {
            l * b = new l (x);
            b->next = m.left;
            m.left->parent=b;
            m.left = b;
            float current2 = float( clock () - begin_time1 ) /  CLOCKS_PER_SEC;
            std::cout<< "\t\t>>#1 time >> "<<current2 <<endl;
            cout<<"\n\n\n"<<endl;
            return 0;
        }
        float current2 = float( clock () - begin_time1 ) /  CLOCKS_PER_SEC;
        std::cout<< "\t\t>>Milestone 1 >> "<<current2 <<endl;
    }
    else {
        l * b = new l (x);
        b->next=NULL;
        m.left=b;
        m.left_end=b;
        m.left_end->parent=NULL;
        float current2 = float( clock () - begin_time1 ) /  CLOCKS_PER_SEC;
        std::cout<< "\t\t>>Milestone 1 >> "<<current2 <<endl;
        cout<<"\n\n\n"<<endl;
        return 0;
    }
    const clock_t begin_time3 = clock();
    if(m.left_end->value>x)
    {
        l * b = new l (x);
        b->next=NULL;
        // b->parent = m.left_end;
        m.left_end->next=b;
        b->parent=m.left_end;
        m.left_end=b;
        // cout<<"DONE"<<endl;
        float current3 = float( clock () - begin_time3 ) /  CLOCKS_PER_SEC;
                std::cout<< "\t\t>>#2 >> "<<current3 <<endl;

                cout<<"\n\n\n"<<endl;
        return 0;

    }
    const clock_t begin_time = clock();
    float current3 = float( clock () - begin_time3 ) /  CLOCKS_PER_SEC;
            std::cout<< "\t\t>>Milestone 2 >> "<<current3 <<endl;



    const clock_t begin_time6 = clock();

    l * left = m.left;
    bool flag = false;
    int i=0;
    l * prev = left;
    float current4 = float( clock () - begin_time6 ) /  CLOCKS_PER_SEC;
    std::cout<< "\t\t>>Milestone 3 >> "<<current4 <<endl;

    while(left)
    {i++;
        if(left->value < x)
        {
            l * b = new l (x);
            b->next = left;

            if(prev!=left)
            {
                prev->next=b;
                b->parent = prev;
            }
            float current2 = float( clock () - begin_time ) /  CLOCKS_PER_SEC;

                            std::cout<< "\t\t>>INSIDE Rellocate Left Time >> "<<current2 <<endl;
                            cout<<"\n\n\n"<<endl;
                            cout<<"I is " << i <<endl;
            return 0 ;
            flag=true;

            break;

        }
        else {
            prev = left;
            left = left->next;
        }
    }
    cout<<"I is " << i <<endl;
    if(flag==false)
    {
        l * b = new l (x);
        b->next=NULL;
        if(prev)
        {
        prev->next=b;
        b->parent = prev;
        }
        else {
        m.left=b;
        }
        m.left_end=b;
    }
    float current2 = float( clock () - begin_time ) /  CLOCKS_PER_SEC;

                    std::cout<< "\t\t>> INSIDE Rellocate Left Time >> "<<current2 <<endl;
                    cout<<"\n\n\n"<<endl;
    return 0;
}
inline bool reallocate_right(int x)
{
    // cout<<"Malek el Deda "<<endl;
    if(m.right)
    {
        // cout<<"Now we compare right between > " << m.right->value << " and > " << x <<endl;
        if(m.right->value>x)
        {
            // cout<<"bb"<<endl;
            r * b = new r (x);
            b->next = m.right;
            m.right = b;
            return 0;
        }
    }
    else {
        // cout<<"deda"<<endl;
            r * b = new r (x);
            b->next=NULL;
            m.right=b;
            m.right_end=b;
            m.right_end->parent=NULL;
            return 0;
    }

    if(m.right_end->value < x)
    {
        r * b = new r (x);
        b->next=NULL;
        m.right_end->next=b;
        b->parent=m.right_end;
        m.right_end=b;
        // cout<<"DONE@@@"<<endl;
        return 0;

    }
    int i = 0 ;

    r* left = m.right;
    bool flag = false;
    r* prev = left;
    while(left)
    {
    	i++;
        if(left->value > x)
        {
            r * b = new r (x);
            b->next = left;
            if(prev!=left)
            {
                prev->next=b;
                b->parent = prev;
            }
            return 0 ;
            flag=true;
            // cout<<"VVVVVVVVVVVVVV"    <<endl;
            break;
        }
        else {
            prev = left;
            left = left->next;
        }
    }
    cout <<"I is = " << i <<endl;
    if(flag==false)
    {
        r * b = new r (x);
        b->next=NULL;
        if(prev)
        {
            prev->next=b;
            b->parent = prev;
        }
        else {
        m.right=b;
        }
        m.right_end=b;
    }
    return 0;
}


inline bool add (long long int x)

{
    // cout<<"add started"<<endl;
    if(!m.init)
    {
        m.init=true;
        m.value=x;
        m.mid=true;
        print();
        return 0 ;
        // Printing in the end of the add based on the mid value
    }
    else {
        if(m.mid)
        {
            // cout << "MID"<<endl;
            m.mid=false;
            if(x<=m.value)
            {
//                m.l_num++;
                // shift the value of the m to the right side
                r * b = new r (m.value);
                b->next = m.right;
                if(!m.right)
                {
                    // cout<<"RIGHT"<<endl;
                    m.right_end=b;
                    m.right_end->parent=NULL;
                }
                else
                m.right->parent=b;
                m.right=b;
                // need to reallocate the value of the x in the left side
                const clock_t begin_time = clock();

                reallocate_left(x);
                float current2 = float( clock () - begin_time ) /  CLOCKS_PER_SEC;

                                std::cout<< "\t>> Rellocate Left Time >> "<<current2 <<endl;
                const clock_t begin_time1 = clock();
                print();
                current2 = float( clock () - begin_time1 ) /  CLOCKS_PER_SEC;

                                std::cout<< "\t>> printing Time >> "<<current2 <<endl;
                                return 0 ;
            }
            else if(x>=m.value)
            {
//                m.r_num++;
                // shift the value of the m to the left side
                l * b = new l (m.value);
                b->next = m.left;
                if(!m.left)
                {
                    // cout<<"LEFT"<<endl;
                    m.left_end=b;
                    m.left_end->parent=NULL;
                }
                else
                m.left->parent=b;
                m.left = b;
                // need to reallocate the value of the x in the right side
                reallocate_right(x);
                print();
                                return 0 ;
            }

        } // end of the if(mid)
        else
        {
            m.mid=true;
            bool flag = false;
            if(m.left)
            {
                if(m.left->value>=x)
                {
//                    flag = true;
                    m.value = m.left->value;
                    if(m.left->next)
                    m.left->next->parent=NULL;
                    m.left  = m.left->next;

                    // need to reallocate the value of the x in the left side
                    reallocate_left(x);
                    print();
                                    return 0 ;
                }// end of m.left->value>=x

            }//end of checking the m.left
            if((m.right)&&flag==false)
            {
                if(m.right->value<=x)
                {
                    m.value = m.right->value;
                    if(m.right->next)
                    m.right->next->parent=NULL;
                    m.right = m.right->next;
                    // need to reallocate the value of the x in the right side
                    reallocate_right(x);
                    print();
                                    return 0 ;
                }// end of the m.right->value<=x
                else {
                    // when left is 4 and right is 6 and x is 5
                    m.value=x;
                }// end of the m.right->value>x
            }
        } // end of the else of (mid)

    }
    // print the value based on the status of mid ;
    // cout<<"Million deda "<<endl;
        print();
        return 0 ;
}


inline bool remove_left (long long int x)
{
    // cout<<"Value of the left is "<<m.left->value<<endl;
    if(m.left->value==x)
    {
        // cout<<"FOUND LEFT"<<endl;
        if(m.left->next)
        m.left->next->parent=NULL;
        m.left=m.left->next;
        if(!m.left)
        m.left_end=m.left;

        return 1;
    }

    auto left = m.left;
    bool flag = false;
    auto prev = left;
    while(left)
    {
        if(left->value == x)
        {
            prev->next=left->next;
            if(left->next)
                left->next->parent=prev;
            if(left == m.left_end)
            m.left_end=prev;
            left=NULL;
            flag=true;
            // cout<<"FOUND LEFT"<<endl;
            return 1;
            break;
        }
        else {
            prev = left;
            left = left->next;
        }
    }
    return 0;
}
inline bool remove_right (long long int x)
{
    // cout<<"Value of the right is "<<m.right->value<<endl;
    if(m.right->value==x)
    {
        if(m.right->next)
        m.right->next->parent=NULL;
        m.right=m.right->next;
        if(!m.right)
        m.right_end=m.right;
        // cout<<"FOUND RIGHT"<<endl;
        return 1;
    }
    auto left = m.right;
    bool flag = false;
    auto prev = left;


    while(left)
    {
        if(left->value == x)
        {
            prev->next=left->next;
            if(left->next)
                        left->next->parent=prev;
            if(left == m.right_end)
            m.right_end=prev;
            left=NULL;
            flag=true;
            // cout<<"FOUND RIGHT"<<endl;
            return 1;
            break;
        }
        else {
            prev = left;
            left = left->next;
        }
    }

return 0;
}



inline bool erase (long long int x)
{
    if(!m.init)
    {
        // cout<<"1";
//        cout<<"Wrong!"<<endl;
        printf("Wrong!\n");
        return 0 ;
    }
    // cout<<"X is "<<x << " m.mid is ";
    // cout <<m.mid<<endl;
    if(m.mid)
    {
                            // need to be changed if the element found
        if(m.left_end)
        if(m.left_end->value==x)
        {
            m.mid=false;
            if(m.left_end->parent)
            {
                m.left_end->parent->next=NULL;
                m.left_end= m.left_end->parent;
            }
            else
            {
                m.left=NULL;
            }
            l * b = new l (m.value);    // shift the m value to the left
            b->next = m.left;           // ...
            if(!m.left)
                m.left_end=b;
            else
                m.left->parent=b;
            m.left = b;                 // ...
            print();

            return 0;
        }
        if(m.right_end)
        if(m.right_end->value==x)
        {
            m.mid=false;
            if(m.right_end->parent)
            {
                m.right_end->parent->next=NULL;
                m.right_end= m.right_end->parent;
            }
            else
            {
                m.right=NULL;
            }
            r * b = new r (m.value);    // shift the m value to the left
            b->next = m.right;           // ...
            if(!m.right)
                m.right_end=b;
            else
                m.right->parent=b;
            m.right = b;                 // ...
            print();
            return 0;


        }
        if(x<m.value)                   // check if x in the left side
        {
            if(m.left)
            {
            if(remove_left(x))             // need to be bool to check if the element found
            {
                m.mid=false;
            l * b = new l (m.value);    // shift the m value to the left
            b->next = m.left;           // ...
            if(!m.left)
            m.left_end=b;
            else
                m.left->parent=b;
            m.left = b;                 // ...
            // remove x
            }
            else
                {
                    // cout<<"2";
//                    cout<<"Wrong!"<<endl;
                printf("Wrong!\n");
                    return 0;
                }
            }
            else
            {
                    {
                        // cout<<"3";
//                        cout<<"Wrong!"<<endl;
                        printf("Wrong!\n");
                        return 0;
                    }
            }
        }
        else if(x>m.value)              // check if x in the right side
        {
            if(m.right)
            {
                if(remove_right(x))            // need to be bool to check if the element found
                {
                    m.mid=false;
                r * b = new r (m.value);    // shift value to the right
                b->next = m.right;          // ...
                if(!m.right)
                    m.right_end=b;
                else
                    m.right->parent=b;
                m.right = b;                // ...
                }
                else
                    {
                        // cout<<"3";
//                        cout<<"Wrong!"<<endl;
                    printf("Wrong!\n");
                        return 0;
                    }
            }
            else
            {
                    {
                        // cout<<"3";
//                        cout<<"Wrong!"<<endl;
                        printf("Wrong!\n");
                        return 0;
                    }
            }
            //remove x
        }
        else if(x==m.value)             // element is the middle element
        {
            m.mid=false;
            // cout<<"activated"<<endl;
            if(!(m.left))               // check if this is the last element
            {
                // cout<<"activated"<<endl;
                if(!(m.right))          // ...
                {
//                    cout<<"activated"<<endl;
                    m.init=false;       // init the m to be free
                }
            }
        }
        else
        {
            // cout<<"3.25";
//            cout<<"Wrong!"<<endl;
            printf("Wrong!\n");
            return 0;
        }
    }
    else {
                                        //
        bool flag = false;

        if(m.left_end)
                if(m.left_end->value==x)
                {
                    // cout<<"LEFT END CHECKED AND DELETED " <<endl;
//                    m.mid=false;
                    if(m.left_end->parent)
                    {
                        // cout<<"Has Parent"<<endl;
                        m.left_end->parent->next=NULL;
                        m.left_end= m.left_end->parent;
                    }
                    else
                    {
                        // cout<<"DOESN'T Have Parent"<<endl;
                        m.left=NULL;
                        m.left_end=NULL;
                    }
                    flag = true;
                    m.value = m.right->value; // shift the right value to the middle
                    if(m.right->next)
                        m.right->next->parent=NULL;
                    m.right  = m.right->next; // ..
                    if(!m.right)
                    {
                        m.right_end=NULL;
                    }
                    m.mid=true;
//                    return 0;

                }
                if((m.right_end)&&flag==false)
                if(m.right_end->value==x)
                {
                    // cout<<"RIGHT END CHECKED AND DELETED " <<endl;
                    m.mid=false;
                    if(m.right_end->parent)
                    {
                        m.right_end->parent->next=NULL;
                        m.right_end= m.right_end->parent;
                    }
                    else
                    {
                        m.right=NULL;
                        m.right_end=NULL;
                    }
                    flag = true;
                    m.value = m.left->value;
                    if(m.left->next)
                        m.left->next->parent=NULL;
                    m.left = m.left->next;
                    if(!m.left)
                    {
                        m.left_end=NULL;
                    }
                    m.mid=true;
//                    return 0;


                }


        if((m.left)&&flag==false)                      // if there is elements in the left
        {
            if(m.left->value>=x)        // check if x is smaller than or equal the left
            {
                if(remove_left(x))
                {
                flag = true;
                m.value = m.right->value; // shift the right value to the middle
                if(m.right->next)
                m.right->next->parent=NULL;
                m.right  = m.right->next; // ...
                m.mid=true;
                // need to rremove the value of the x in the left side
                }
                else
                {
                    // cout<<"3.5";
//                    cout<<"Wrong!"<<endl;
                    printf("Wrong!\n");
                    return 0;
                }

                // remove_left(x);
            }// end of m.left->value>=x
            else {
                flag = false;
            } // end of m.left->value<x

        }//end of checking the m.left
        if(flag==false)
        {
            if(m.right)
            {
                // cout <<"Here " <<endl;
                if(m.right->value<=x)
                {
                    if(remove_right(x))
                    {
                    m.value = m.left->value;
                    if(m.left->next)
                    m.left->next->parent=NULL;
                    m.left = m.left->next;
                    m.mid=true;
                    }
                    else
                    {
                        // cout<<"4";
//                        cout<<"Wrong!"<<endl;
                        printf("Wrong!\n");
                        return 0;
                    }
                    // need to remove the value of the x in the right side

                }
                else
                    {
                        // cout<<"5";
//                        cout<<"Wrong!"<<endl;
                    printf("Wrong!\n");
                        return 0;
                    }

                // end of the m.right->value<=x
                // else {
                //     // when left is 4 and right is 6 and x is 5
                //     m.value=x;
                // }// end of the m.right->value>x
            }
            else
                {
                    // cout<<"6";
//                    cout<<"Wrong!"<<endl;
                printf("Wrong!\n");
                    return 0;
                }

        }
    }
    if(m.init)
    print();
    else
    {
        // cout<<"7";
        r *b = new r (8);
        l *v = new l (8);
        m.right_end=b->next;
        m.left_end=v->next;
//        cout<<"Wrong!"<<endl;
        printf("Wrong!\n");
        return 0 ;
    }

    return 0;
}



int main(void){

//Helpers for input and output
//    multiset <long long int> x;
    int N;
    float times =0.0;
    float current =0.0;
    cin >> N;
    // cout<<std::defaultfloat;;
    // std::cout<<std::cout.precision();

    vector<char> s;
    vector<long long int> x;
    char temp;
    long long int tempint;
    for(int i = 0; i < N; i++){
         cin >> temp >> tempint;
//        scanf("%c %lld\n",&temp,&tempint);
        s.push_back(temp);
        x.push_back(tempint);
    }
        // scanf("")
        // cout<<" ROUND NUMBER IS >> " << i <<endl;
        // cout<<"> " << temp<<" > " <<tempint <<endl;
        // cout<<"Left is " << m.l_num<< " Right is " << m.r_num <<endl;
        // s.push_back(temp);
        // X.push_back(tempint);
    int  i = 0 ;
    cout<<"START"<<endl;
    for(auto temp : s)
    {
    	tempint = x[i];
        if(temp == 'a')
        {
            // x.insert(tempint);
        	const clock_t begin_time = clock();
            cout<<std::fixed;;
            add(tempint);
            current = float( clock () - begin_time ) /  CLOCKS_PER_SEC;
            times = times + current;
            std::cout<< ">> " << i<<" ADDING** Time >> "<<current << "\t Total = "<< times <<endl;
        }
        else if(temp == 'r')
        {
        	const clock_t begin_time = clock();
            cout<<std::fixed;;
            erase(tempint);
            current = float( clock () - begin_time ) /  CLOCKS_PER_SEC;
            times = times + current;
            std::cout<< ">> " << i <<"REMOVING Time >> "<<current << "\t Total = "<< times <<endl;
            // auto it = x.find(tempint);
            // if(it!=x.end())
            // {
            //     // cout << "erase " << *it <<endl;
            //     x.erase(it);
            //     // erase(tempint);
            // }
            // // else
            // {
            //     cout<<"Wrong!"<<endl;
            // }
        }
        i++;
// //     if(i>32&&i<40)
//          {
//          int ll = 0 ;
//          for (auto m : x)
//          {
//              cout<<ll << " >> "<<m<<endl;
//              ll++;
//          }
          auto b = m.left;
          auto c = m.right;
          int yy = 0 ;
          while(b)
          {
//              cout << yy <<" ";
//              cout<<"L > "<<b->value<<endl;
              b=b->next;
              yy++;
          }
          cout<<"left is " << yy <<" ";
          yy=0;
          while(c)
          {
//              cout << yy <<" ";
//              cout<<"R > "<<c->value<<endl;
              c=c->next;
              yy++;
          }
          cout<<"right is " << yy <<"\n";

//          // cout<<"i is >> "<<i+1<<endl<<endl;
//          }
//          cout<<"%%%%% >> M is >> " << m.value <<endl;
// //         cout<<endl<<endl;
//          if(m.right_end)
//          cout<<"RIGHT END IS = "<< m.right_end->value <<endl;
//          if(m.left_end)
//          cout<<"LEFT END IS = "<< m.left_end->value <<endl;

    }
    // median(s,X);
    return 0;

}
