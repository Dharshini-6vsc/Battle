#include "student.h"

/*
 * Fixed dataset of 40 unique student records.
 * The same records and insertion order are used for BST, AVL and Hashing.
 */
Student students[DATASET_SIZE] = {
    {1134, "Lavanya",    "CSE",  8.9f},
    {1029, "Rahul",      "IT",   8.2f},
    {1204, "Deepa",      "CSE",  8.8f},
    {1071, "Bharath",    "ECE",  7.9f},
    {1246, "Sowmya",     "EEE",  8.6f},
    {1015, "Karthik",    "ECE",  7.8f},
    {1169, "Naveen",     "CSE",  8.2f},
    {1099, "Suresh",     "MECH", 7.7f},
    {1267, "Ramesh",     "ECE",  7.8f},
    {1043, "Vikram",     "MECH", 7.6f},
    {1218, "Ramya",      "IT",   9.2f},
    {1120, "Harini",     "AIML", 9.4f},
    {1001, "Arun",       "CSE",  8.5f},
    {1190, "Monisha",    "AIML", 9.3f},
    {1085, "Rohit",      "CSE",  8.4f},
    {1232, "Kavya",      "AIML", 9.1f},
    {1057, "Santhosh",   "CSE",  8.0f},
    {1148, "Swetha",     "EEE",  9.1f},
    {1022, "Divya",      "CSE",  8.9f},
    {1253, "Ashwin",     "IT",   8.3f},
    {1106, "Pavithra",   "IT",   8.6f},
    {1176, "Janani",     "ECE",  8.7f},
    {1008, "Priya",      "AIML", 9.1f},
    {1211, "Vishal",     "MECH", 7.6f},
    {1078, "Keerthana",  "AIML", 8.8f},
    {1274, "Ishita",     "CSE",  9.5f},
    {1036, "Sneha",      "AIML", 9.3f},
    {1162, "Aishwarya",  "AIML", 9.0f},
    {1113, "Gokul",      "CSE",  8.1f},
    {1239, "Madhan",     "CSE",  7.7f},
    {1068, "Anitha",     "IT",   9.0f},
    {1197, "Ajay",       "EEE",  8.0f},
    {1092, "Nithya",     "EEE",  9.2f},
    {1260, "Gayathri",   "AIML", 9.0f},
    {1050, "Meena",      "EEE",  8.7f},
    {1155, "Dinesh",     "MECH", 7.8f},
    {1127, "Manoj",      "ECE",  7.5f},
    {1225, "Surya",      "ECE",  8.4f},
    {1141, "Praveen",    "IT",   8.3f},
    {1183, "Sanjay",     "IT",   7.9f}

};

void load_dataset(Student records[], int count) {
    int i;
    for (i = 0; i < count && i < DATASET_SIZE; i++) {
        records[i] = students[i];
    }
}
