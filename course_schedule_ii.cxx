//
//  Course Schedule II
//  https://leetcode.com/problems/course-schedule-ii/
//  
//  Given a list of pairs, each being (course, prerequisite), determine
//  a valid ordering to take every course sequentially. Return this as
//  a vector, or empty vector if impossible.
//
//  Joel Rorseth
//  Created on June 21, 2017
//

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

// Solution (BFS)
std::vector<int> find_order(int num_courses, std::vector<std::pair<int, int>> & prerequisites) {

    std::vector<int> ordered_retval;
    std::vector<std::vector<int>> graph(num_courses, std::vector<int>(0));
    std::vector<int> prerequisites_count(num_courses, 0);

    // Make graph of prerequisites to corresponding courses with dependencies
    for (auto & a: prerequisites) {
        graph[a.second].push_back(a.first);
        prerequisites_count[a.first]++;
    }

    std::queue<int> no_prerequisites;

    // Make a queue with all courses that have no prerequisites
    for (int i = 0; i < num_courses; ++i) 
        if (prerequisites_count[i] == 0) 
            no_prerequisites.push(i);

    while (!no_prerequisites.empty()) {

        // Next course in order to take is in no_prerequisites
        // It no longer had any prerequisites, so it was added

        int next = no_prerequisites.front();
        no_prerequisites.pop();
        ordered_retval.push_back(next);

        // For each course that has 'next' as a prerequisite, if that was
        // its only prerequisite, add it to the queue (thus eventually retval)
        for (auto & course_with_prerequisite: graph[next]) 

            // Safe to add to queue for retval if no more dependencies
            if(--prerequisites_count[course_with_prerequisite] == 0) 
                no_prerequisites.push(course_with_prerequisite);
    }

    // If not all courses were accounted for, impossible to solve
    if(ordered_retval.size() != num_courses) 
        ordered_retval.clear();

    return ordered_retval;
}


// Demonstration
int main() {

    std::cout << "Given prerequisites: [1,0], [2,0], [3,1], [4,3], [4,2]"
        << "\nValid ordering: ";

    std::vector<std::pair<int, int>> a{
        std::make_pair(1,0),std::make_pair(2,0),std::make_pair(3,1),
            std::make_pair(4,3),std::make_pair(4,2)};

    for (auto i: find_order(5, a))
        std::cout << i << ',' << ' ';
    std::cout << std::endl;
}