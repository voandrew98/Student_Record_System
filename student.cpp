#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "student.h"


void Student::print(ofstream& output) //works
{
  student *current = head;
  while(current != nullptr)
  {
    output << "{id:" << current->id << "," << current->first << "," << current->last << "," << current->dob << "," << current->gpa << "}" << endl;
    current = current->next; //why doesnt output work here?
  }
}

void Student::add(string id, string first, string last, string dob, string gpa) //works
{
    student *node = new student;
    student *point = new student;
    
    point = head;

    while(point != nullptr)
    {
      if(point->id == id)
      {
        point->id = id;
        point->first = first;
        point->last = last;
        point->dob = dob;
        point->gpa = gpa;
        return;
      }
      point = point->next;
    }
    
    node->id = id;
    node->first = first;
    node->last = last;
    node->dob = dob;
    node->gpa = gpa;
    
    node->next = nullptr;

    if(head == nullptr)
    {
      head = node;
    } else
    {
      student* temp = head;
      while(temp->next != nullptr)
      {
        temp = temp->next;
      }
      temp->next = node;
      tail = temp->next;
    }  
}

void Student::deleteNode(string str) //works
{
  student *current = new student;
  student *prev = new student;

  current = head;
  prev = nullptr;

  if(current-> id == str)
  {
    head = current->next;
    delete current;
    return;
  }
  else
  {
    while(current != nullptr && current-> id != str)
    {
      prev = current;
      current = current->next;
    }
    if (current == nullptr)
    {
      return;
    }
    else if(current->id == tail->id)
    {
      tail = prev;
    }
    prev->next = current->next;
    delete current;
  }
}

void Student::swap(student *point1, student *point2) //works
{
  student *temp = new student;
  temp->id = point2->id;
  temp->first = point2->first;
  temp->last = point2->last;
  temp->dob = point2->dob;
  temp->gpa = point2->gpa;

  point2->id = point1->id;
  point2->first = point1->first;
  point2->last = point1->last;
  point2->dob = point1->dob;
  point2->gpa = point1->gpa;

  point1->id = temp->id;
  point1->first = temp->first;
  point1->last = temp->last;
  point1->dob = temp->dob;
  point1->gpa = temp->gpa;
}

void Student::bubbleSort(string sortname)//works
{
  student* current = new student;
  student* prev = new student;

  int count_swaps = 1;
  while(count_swaps)
  {
    if(sortname == "id")
    {
      count_swaps = 0;
      current = head->next;
      prev = head;
      while(current != nullptr)
      {
        if(current->id < prev->id)
        {
          swap(current, prev);
            count_swaps = 1;
        }
        prev = current;
        current = current->next;
      }
    }
    if(sortname == "DOB")
    {
      count_swaps = 0;
      current = head->next;
      prev = head;
      while(current != nullptr)
      {
        if(current->dob < prev->dob)
        {
          swap(current, prev);
            count_swaps = 1;
        }
        prev = current;
        current = current->next;
      }
    }
    if(sortname == "first")
    {
      count_swaps = 0;
      current = head->next;
      prev = head;
      while(current != nullptr)
      {
        if(current->first < prev->first)
        {
          swap(current, prev);
            count_swaps = 1;
        }
        prev = current;
        current = current->next;
      }
    }
    if(sortname == "last")
    {
      count_swaps = 0;
      current = head->next;
      prev = head;
      while(current != nullptr)
      {
        if(current->last < prev->last)
        {
          swap(current, prev);
            count_swaps = 1;
        }
        prev = current;
        current = current->next;
      }
    }
    if(sortname == "GPA")
    {
      count_swaps = 0;
      current = head->next;
      prev = head;
      while(current != nullptr)
      {
        if(current->gpa < prev->gpa)
        {
          swap(current, prev);
            count_swaps = 1;
        }
        prev = current;
        current = current->next;
      }
    }
  }
}
void Student::openFile(ifstream& sort) //not working
{
  string strData;
  while(getline(sort,strData))
  {
    strData.erase(remove(strData.begin(),strData.end(),'\n'),strData.end());
    strData.erase(remove(strData.begin(),strData.end(),'\r'),strData.end());
    if(strData !="")
    {
      bubbleSort(strData);
    }
  }
}
