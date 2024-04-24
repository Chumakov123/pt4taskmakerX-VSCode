#pragma once
#include"pt4taskmakerX.h"

template<typename T>
inline void pt4taskmakerX::Data(const char* comm, T a) {
	if (CheckTT()) return;
	++yd;
	DataInternal(comm, a, 0, yd, wd);
}
template<typename T>
inline void pt4taskmakerX::Data(const char* comm1, T a1, const char* comm2) {
	if (CheckTT()) return;
    ++yd;
    DataInternal(comm1, a1, xLeft, yd, wd);
    pt4taskmaker::DataComment(comm2, xRight, yd);
}
template<typename T1, typename T2>
inline void pt4taskmakerX::Data(const char* comm1, T1 a1, const char* comm2, T2 a2) {
	if (CheckTT()) return;
	++yd;
    DataInternal(comm1, a1, xLeft, yd, wd);
    DataInternal(comm2, a2, xRight, yd, wd);
}
template<typename T1, typename T2>
inline void pt4taskmakerX::Data(const char* comm1, T1 a1, const char* comm2, T2 a2, const char* comm3) {
	if (CheckTT()) return;
    ++yd;
    DataInternal(comm1, a1, xLeft, yd, wd);
    DataInternal(comm2, a2, 0, yd, wd);
    pt4taskmaker::DataComment(comm3, xRight, yd);
}
template<typename T1, typename T2, typename T3>
inline void pt4taskmakerX::Data(const char* comm1, T1 a1, const char* comm2, T2 a2, const char* comm3, T3 a3) {
	if (CheckTT()) return;
    ++yd;
    DataInternal(comm1, a1, xLeft, yd, wd);
    DataInternal(comm2, a2, 0, yd, wd);
    DataInternal(comm3, a3, xRight, yd, wd);
}

template<typename T>
inline void DataInternal(const char* s, T a, int x, int y, int w) {
    if ((y > 5) && fd) {
        ErrorInfo(ErrMes2);
        return;
    }
    ++nd;
    if (nd > 200) {
        ErrorInfo(ErrMes3);
        return;
    }
    pt4taskmakerX::Data(s, a, x, y, w);
}

template<typename T>
inline void pt4taskmakerX::Res(const char* comm, T a) {
	if (CheckTT()) return;
	++yd;
	ResInternal(comm, a, 0, yd, wd);
}
template<typename T>
inline void pt4taskmakerX::Res(const char* comm1, T a1, const char* comm2) {
	if (CheckTT()) return;
    ++yd;
    ResInternal(comm1, a1, xLeft, yd, wd);
    pt4taskmaker::ResultComment(comm2, xRight, yd);
}
template<typename T1, typename T2>
inline void pt4taskmakerX::Res(const char* comm1, T1 a1, const char* comm2, T2 a2) {
	if (CheckTT()) return;
	++yd;
    ResInternal(comm1, a1, xLeft, yd, wd);
    ResInternal(comm2, a2, xRight, yd, wd);
}
template<typename T1, typename T2>
inline void pt4taskmakerX::Res(const char* comm1, T1 a1, const char* comm2, T2 a2, const char* comm3) {
	if (CheckTT()) return;
    ++yd;
    ResInternal(comm1, a1, xLeft, yd, wd);
    ResInternal(comm2, a2, 0, yd, wd);
    pt4taskmaker::ResultComment(comm3, xRight, yd);
}
template<typename T1, typename T2, typename T3>
inline void pt4taskmakerX::Res(const char* comm1, T1 a1, const char* comm2, T2 a2, const char* comm3, T3 a3) {
	if (CheckTT()) return;
    ++yd;
    ResInternal(comm1, a1, xLeft, yd, wd);
    ResInternal(comm2, a2, 0, yd, wd);
    ResInternal(comm3, a3, xRight, yd, wd);
}


template<typename T>
inline void ResInternal(const char* s, T a, int x, int y, int w) {
	if ((y > 5) && fr) {
		ErrorInfo(ErrMes2);
		return;
	}
	++nr;
	if (nr > 200) {
		ErrorInfo(ErrMes4);
		return;
	}
    pt4taskmakerX::Res(s, a, x, y, w);
}