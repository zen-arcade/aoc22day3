#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int getDupePriorities(std::string sack) //part 1
{
    int len{sack.length()};
    std::string compartment1{sack.substr(0,len/2)};
    std::string compartment2{sack.substr(len/2,len/2)};
    int dupePrioritySum{0};
    for(int i=0;i<compartment1.length();i++)
    {
        for(int j=0;j<compartment2.length();j++)
        {
            if(compartment1[i]==compartment2[j])
            {
                if(compartment1[i]<'a')
                    dupePrioritySum=compartment1[i]-'A'+27; //character smaller than 'a' means it is uppercase, priority starts at 27
                else
                    dupePrioritySum=compartment1[i]-'a'+1; //else it's lowercase, priority starts at 1
            }
        }
    }
    return dupePrioritySum;
}

int findGroupBadges(std::vector<std::string> sackGroup) //part 2
{
    int groupPrioritySum{};
    for(int i=0;i<sackGroup.size();i+=3)
    {
        std::string sack1{sackGroup[i]},sack2{sackGroup[i+1]},sack3{sackGroup[i+2]};
        for(int j=0;j<sack1.length();j++)
        {
            char item{sack1[j]};
            if(sack2.find(item) != std::string::npos && sack3.find(item) != std::string::npos)
            {
                if(item<'a')
                    groupPrioritySum+=item-'A'+27;
                else
                    groupPrioritySum+=item-'a'+1;
                break; //break out of this loop, badge found
            }
        }
    }
    return groupPrioritySum;
}

int main()
{
    std::string line{};
    std::ifstream sacks{"input.txt"};
    std::vector<std::string> sackGroup{};
    int sum{};
    while(std::getline(sacks,line))
    {
        sackGroup.push_back(line);
        sum+=getDupePriorities(line);
    }
    std::cout<<"The sum of priorities is: "<<sum<<'\n';
    std::cout<<"The group priority sum is: "<<findGroupBadges(sackGroup)<<'\n';
    return 0;
}
