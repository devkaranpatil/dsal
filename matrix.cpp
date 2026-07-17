#include <iostream>
#include <iomanip>
using namespace std;

class MatrixOperations
{
private:
    int matrix1[3][3];
    int matrix2[3][3];
    int sumMatrix[3][3];
    int subMatrix[3][3];
    int multiplyMatrix[3][3];

    void inputMatrix(int matrix[3][3], const char *name)
    {
        cout << "Enter " << name << " (3x3):\n";
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                cout << name << " [" << i + 1 << "][" << j + 1 << "]: ";
                cin >> matrix[i][j];
            }
        }
        cout << '\n';
    }

    void displayMatrix(const int matrix[3][3], const char *label) const
    {
        cout << label << "\n";
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                cout << matrix[i][j] << " ";
            }
            cout << '\n';
        }
        cout << '\n';
    }

public:
    void inputMatrices()
    {
        inputMatrix(matrix1, "Matrix 1");
        inputMatrix(matrix2, "Matrix 2");
    }

    void displayMatrices() const
    {
        displayMatrix(matrix1, "Matrix 1");
        displayMatrix(matrix2, "Matrix 2");
    }

    void addMatrices()
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                sumMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
    }

    void subtractMatrices()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                subMatrix[i][j] = matrix1[i][j] - matrix2[i][j];
            }
        }
    }

    void multiplyMatrices()
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                multiplyMatrix[i][j] = 0;
                for (int k = 0; k < 3; ++k)
                {
                    multiplyMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
    }

    void displaySum() const
    {
        displayMatrix(sumMatrix, "Sum of the two matrices:");
    }

    void displayDifference() const
    {
        displayMatrix(subMatrix, "Difference of the two matrices:");
    }

    void displayProduct() const
    {
        displayMatrix(multiplyMatrix, "Product of the two matrices:");
    }
};

int main()
{
    MatrixOperations matrix;
    int choice = 0;
    bool running = true;

    matrix.inputMatrices();

    while (running)
    {
        cout << "\nMatrix Menu\n";
        cout << "1. Add matrices\n";
        cout << "2. Subtract matrices\n";
        cout << "3. Multiply matrices\n";
        cout << "4. Display input matrices\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            matrix.addMatrices();
            matrix.displaySum();
            break;
        case 2:
            matrix.subtractMatrices();
            matrix.displayDifference();
            break;
        case 3:
            matrix.multiplyMatrices();
            matrix.displayProduct();
            break;
        case 4:
            matrix.displayMatrices();
            break;
        case 5:
            running = false;
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            exit(1);
        }
    }

    return 0;
}