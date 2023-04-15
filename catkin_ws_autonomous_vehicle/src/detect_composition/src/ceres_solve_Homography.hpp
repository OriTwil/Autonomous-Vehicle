#include <iostream>
#include <opencv2/core/core.hpp>
#include <ceres/ceres.h>
#include <chrono>

using namespace std;
using namespace ceres;
struct CostFunctor
{
    CostFunctor(vector<double> &x, vector<double> &y) : _x(x), _y(y) {}
    template <typename T>
    bool operator()(const T *const T, T *residual) const
    {
        residual[0] = _y[0] - (T[0] * _x[0] + T[1] * _x[1] + T[2] * _x[2]);
        residual[1] = _y[1] - (T[3] * _x[0] + T[4] * _x[1] + T[5] * _x[2]);
        residual[2] = _y[3] - (T[6] * _x[0] + T[7] * _x[1] + T[8] * _x[2]);
        return true;
    }
    const vector<double> _x, _y;
};

void SolveHomography()
{
    cv::Mat initial_T;
    initial_T = (cv::Mat_<double>(3, 3) << 1, 0, 0, 0, 1, 0, 0, 0, 1);
    int N = 100;
    cv::Mat T = initial_T.clone();

    Problem problem;
    for (int i = 0; i < N; i++)
    {
        CostFunction *cost_function = new AutoDiffCostFunction<CostFunctor, 1, 9>(new CostFunctor);
        problem.AddResidualBlock(cost_function, NULL, &T);
    }
}
