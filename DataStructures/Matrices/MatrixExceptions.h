//
// Created by indy on 6/14/23.
#pragma once
#include <exception>


class MatrixDimensionsIncompatible : public std::exception
{
} MatrixImcompatible;

class NonSquareMatrixCannotBeInverted : public std::exception
{

} NonSquareInversion;