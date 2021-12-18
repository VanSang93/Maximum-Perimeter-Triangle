#include <iostream>
#include <vector>

bool isTriangle(int x, int y, int z)
{
    if ((x + y <= z) || (y + z <= x) || (z + x <= y))
    {
        return false;
    }
    return true;
}

std::vector<int> maximumPerimeterTriangle(std::vector<int> sticks)
{
    size_t n = sticks.size();
    std::cout << n;
    //in the case n < 3
    if (static_cast<int>(n) < 3)
    {
        std::vector<int> v{-1};
        return v;
    }

    //if n >= 3 find the valid triangle and calculate the perimeter
    std::vector<int> result(3);
    int maxPerimeter{0};

    for (size_t i{0}; i < n - 2; ++i)
    {
        for (size_t j = i + 1; j < n - 1; ++j)
        {
            for (size_t k = {j + 1}; k < n; ++k)
            {
                if (isTriangle(sticks[i], sticks[j], sticks[k]))
                {
                    int perimeter = sticks[i] + sticks[j] + sticks[k];
                    if (perimeter > maxPerimeter)
                    {
                        result[0] = sticks[i];
                        result[1] = sticks[j];
                        result[2] = sticks[k];
                        maxPerimeter = perimeter;
                    }
                }
            }
        }
    }
    if (maxPerimeter == 0)
    {
        std::vector<int> v{-1};
        return v;
    }
    return result;
}

int main()
{
    std::cout << "Enter n (3 <= n <= 50): ";
    int n{};
    std::cin >> n;

    std::vector<int> sticks(n);

    for (size_t i{0}; i < n; ++i)
    {
        std::cin >> sticks[i];
    }

    std::vector<int> result = maximumPerimeterTriangle(sticks);

    for (int x : result)
    {
        std::cout << x << ' ';
    }

    return 0;
}