#include <array>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int> round_scores{};
    round_scores.reserve(student_scores.size());

    for (const auto& score : student_scores) {
        round_scores.push_back(static_cast<int>(score));
    }

    return round_scores;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    uint32_t failed_students_count = 0;

    for (const auto& score : student_scores) {
        if (score <= 40) {
            failed_students_count++;
        }
    }

    return failed_students_count;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    std::array<int, 4> grades{};
    
    grades[0] = 41;
    
    uint32_t count = 1;
    uint32_t step = (highest_score - 40) / 4;
    uint32_t current_grade = grades[0] + step;

    while (current_grade < highest_score) {
        grades[count] = current_grade;
        current_grade += step;
        count++;
    }
    
    return grades;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
    
    std::vector<std::string> ranking{};
    ranking.reserve(student_scores.size());

    for (uint32_t rank = 1; rank <= student_scores.size(); rank++) {
        ranking.push_back(std::to_string(rank) + ". " + student_names[rank - 1] + ": " + std::to_string(student_scores[rank - 1]));
    }
 
    return ranking;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    for (uint32_t i = 0; i < student_scores.size(); i++) {
        if (student_scores[i] == 100) {
            return student_names[i];
        }
    }

    return "";
}
