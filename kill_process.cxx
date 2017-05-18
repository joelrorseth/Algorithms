//
//  Kill Process
//  https://leetcode.com/problems/kill-process/
//  
//  Given a tree PID structure, where 0 is the root PID, return
//  a list of all PIDs that would be deleted when killing a 
//  specific PID. You are given a PID to be killed, a list of PIDs 
//  'pid', and a second list 'ppid' that denotes the parent process
//  of the corresponding PID at the same index in 'pid'.
//
//         6         In this example, you would be given:
//       /   \       pid =  [3, 2, 6, 5, 9]
//      3     5      ppid = [6, 3, 0, 6, 5]
//       \     \
//        2     9    kill_process(5) = [5, 9]
//
//  Joel Rorseth
//  Created on May 16, 2017
//

#include <iostream>
#include <vector>
#include <set>
#include <map>


// Print
void print(std::vector<int> & v) {

    std::cout << '[';
    for (auto i: v)
        std::cout << i << ", ";
    std::cout << ']' << std::endl;
}


// Solution (DFS)
void kill_all(std::map<int, std::set<int>> & children, std::vector<int> & killed, int kill) {
    killed.push_back(kill);

    // For each child PID of the process being killed...
    for (auto child: children[kill])
        kill_all(children, killed, child);
}

// Solution
std::vector<int> kill_process
    (std::vector<int> & pid, std::vector<int> & ppid, int kill) {

    std::vector<int> killed;
    std::map<int, std::set<int>> children;

    // Map each PPID existing to a set of its children
    for (auto i = 0; i < pid.size(); ++i)
        children[ppid[i]].insert(pid[i]);

    kill_all(children, killed, kill);
    return killed;
}


// Demonstration
int main() {

    std::vector<int> pid{3, 2, 6, 5, 9};
    std::vector<int> ppid{6, 3, 0, 6, 5};

    std::cout << "pid = ";
    print(pid);
    std::cout << "ppid = ";
    print(ppid);

    auto retval = kill_process(pid, ppid, 5);
    std::cout << "\nKilling 5 would kill: ";
    print(retval);
}
