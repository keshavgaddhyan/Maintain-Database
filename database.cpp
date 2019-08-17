#include <vector>
#include <algorithm>
#include <iostream>
#include "database.h"
#include <string>
using namespace std;

bool operator<(const Profile & a , const Profile & b)
{
    if(a.name<b.name)
    return true;
    if(a.name>b.name)
    return false;
    if(a.name==b.name)
    return (a.studentID<b.studentID);
    
}

bool operator<(const Grade & a , const Grade & b)
{
  if(a.mark<b.mark)
    return true;
    if(a.mark>b.mark)
    return false;
    if(a.mark==b.mark)
    return (a.studentID<b.studentID); 
}
bool Database::add_profile(string id,string name, string phone)
{
    vector<Profile>::iterator itr;
    for(itr=p.begin();itr!=p.end();itr++)
    {
        if((*itr).studentID==id)
        {
            (*itr).name=name;
            (*itr).phoneNumber=phone;
            std::cout<<"Profile Updated"<<std::endl;
            return true;
        }
    }
     Profile temp;
     temp.studentID=id;
     temp.name=name;
     temp.phoneNumber=phone;
     p.push_back(temp);
     return true;
}


bool Database::del_profile(string id)
{
    vector<Grade>::iterator itr1;
    vector<Profile>::iterator itr2;
    int count=0;
    for(itr2=p.begin();itr2!=p.end();itr2++)
    {
        if((*itr2).studentID==id)
        {
            p.erase(itr2);
            count++;
        }
    }
    if(count==1)
    {
        for(itr1=g.begin();itr1!=g.end();itr1++)
    {
        if((*itr1).studentID==id)
        {
            g.erase(itr1);
        }
   }
    return true;
    }
 else
 {
     std::cout<<"Record Not Exists"<<std::endl;
     return false;
 }
    }
    
    
bool Database::add_grade(string id,string class_id,double grade)
{
    int count=0;
    vector<Grade>::iterator itr;
    vector<Profile>::iterator itr1;
    for(itr1=p.begin();itr1!=p.end();itr1++)
    {
        if((*itr1).studentID==id)
        {
            count++;
            
    for(itr=g.begin();itr!=g.end();itr++)
    {
        if((*itr).studentID==id && (*itr).classID==class_id)
        {
            (*itr).mark=grade;
            std::cout<<"Grade Updated"<<std::endl;
            return true;
        }
    }
    
    Grade temp;
    temp.studentID=id;
    temp.classID=class_id;
    temp.mark=grade;
    g.push_back(temp);
    return true;}
    }
    if(count==0)
    {
        std::cout<<"Student Not Exists"<<std::endl;
        return false;
    }
}

bool Database::del_grade(string id,string class_id)
{
    int count=0;
    vector<Grade>::iterator itr;
    for(itr=g.begin();itr!=g.end();itr++)
    {
        if((*itr).studentID==id && (*itr).classID==class_id)
        {
            g.erase(itr);
            count++;
            return true;
        }
    }
    if(count==0)
    {
        std::cout<<"Record Not Exists"<<std::endl;
        return false;
    }
}


void Database::display_profiles()
{
    sort(p.begin(),p.end());
    vector<Profile>::iterator itr;
    for(itr=p.begin();itr!=p.end();itr++)
    {
        std::cout<<(*itr).name<<" "<<(*itr).studentID<<" "<<(*itr).phoneNumber<<" "<<std::endl;
    }
}


void Database::display_grades(string class_id)
{
    int count=0;
    double sum=0,avg=0,max,min;
    sort(g.begin(),g.end());
    vector<Grade>::iterator itr;
    vector<Profile>::iterator itr1;
    min=max= (*g.begin()).mark;
    for(itr=g.begin();itr!=g.end();itr++)
    {
        if((*itr).classID==class_id)
        {
            sum=sum+(*itr).mark;
            count++;
            if(min>(*itr).mark)
            min=(*itr).mark;
            if(max<(*itr).mark)
            max=(*itr).mark;
            for(itr1=p.begin();itr1!=p.end();itr1++)
            {
                if((*itr1).studentID==(*itr).studentID)
                {
                    std::cout<<(*itr1).name<<" "<<(*itr1).studentID<<" "<<(*itr).mark<<" "<<std::endl;
                }
            }
        }
    }
    if(count>0)
    {
        std::cout<<"Min "<<min<<std::endl;
        std::cout<<"Max "<<max<<std::endl;
        avg=sum/count;
        std::cout<<"Average "<<avg<<std::endl;
    }
    
}








