// sample_multimap_student_courses.cpp
#include <iostream>
#include <map>
#include <string>

int main()
{
    std::multimap<std::string, std::string> studentCourses;

    // Each student enrolls in multiple courses
    studentCourses.insert(std::make_pair("Alice", "Mathematics"));
    studentCourses.insert(std::make_pair("Alice", "Computer Networks"));
    studentCourses.insert(std::make_pair("Bob", "Physics"));
    studentCourses.insert(std::make_pair("Alice", "Operating Systems"));
    studentCourses.insert(std::make_pair("Carol", "Database Systems"));
    studentCourses.insert(std::make_pair("Bob", "Linear Algebra"));

    std::string name = "Alice";

    std::cout << "Courses enrolled by " << name << ":\n";

    // Retrieve all courses for the specified student
    auto range = studentCourses.equal_range(name);

    for (auto it = range.first; it != range.second; ++it)
    {
        std::cout << "- " << it->second << '\n';
    }

    return 0;
}
