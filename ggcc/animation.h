// point.h
// ggcc数学-点/向量

#ifndef __GGCCMATHPOINT_H__
#define __GGCCMATHPOINT_H__

#include <bits/stdc++.h>

using realn=long double;

#ifndef PI
#define PI 3.14159265358979323846f
#endif

namespace ggcc {

	// 平面直角坐标系点
	struct point2d {
		realn x=0;				// （米m）
		realn y=0;				// （米m）
		void operator +=(const point2d &a);
		void operator -=(const point2d &a);
		void operator >>=(const point2d &a);
		void operator +=(const realn &a);
		void operator -=(const realn &a);
		void operator *=(const realn &a);
		void operator /=(const realn &a);
		point2d(realn X,realn Y) {
			x=X,y=Y;
		}
		point2d() {
			x=0,y=0;
		}
		const point2d operator-() const {
			return point2d(-x, -y);
		}
		point2d Rotate(realn);	// 旋转 
	};

	// 空间直角坐标系点
	struct point3d {
		realn x=0;				// （米m）
		realn y=0;				// （米m）
		realn z=0;				// （米m）
		void operator +=(const point3d &a);
		void operator -=(const point3d &a);
		void operator >>=(const point3d &a);
		void operator +=(const realn &a);
		void operator -=(const realn &a);
		void operator *=(const realn &a);
		void operator /=(const realn &a);
		point3d(realn X,realn Y,realn Z) {
			x=X,y=Y,z=Z;
		}
		point3d() {
			x=0,y=0,z=0;
		}
		const point3d operator-() const {
			return point3d(-x, -y, -z);
		}
		point3d Rotate(point3d,realn);// 旋转 
	};

#define axisX point2d {1,0}
#define axisY point2d {0,1} 
#define axisZ point3d {0,0,1} 
	
	// 声明
	point2d VecUnit(point2d); 
	point3d VecUnit(point3d);
	point2d operator +(const point2d& a,const point2d& b);
	point3d operator +(const point3d& a,const point3d& b);
	point2d operator +(const point2d& a,const realn& b);
	point3d operator +(const point3d& a,const realn& b);
	point2d operator -(const point2d& a,const point2d& b);
	point3d operator -(const point3d& a,const point3d& b);
	point2d operator -(const point2d& a,const realn& b);
	point3d operator -(const point3d& a,const realn& b);
	point2d operator *(const point2d& a,realn t);
	point3d operator *(const point3d& a,realn t);
	point2d operator *(realn t,const point2d& a);
	point3d operator *(realn t,const point3d& a);
	point2d operator /(const point2d& a,realn t);
	point3d operator /(const point3d& a,realn t);
	point2d operator /(realn t,const point2d& a);
	point3d operator /(realn t,const point3d& a);
	realn operator ^(const point2d& a,const point2d& b);
	point3d operator ^(const point3d& a,const point3d& b);

	// 运算符重载
	bool operator ==(const point2d& a,const point2d& b) {
		return abs(a.x-b.x)<=0.0000001&&abs(a.y-b.y)<=0.0000001;
	}
	bool operator ==(const point3d& a,const point3d& b) {
		return abs(a.x-b.x)<=0.0000001&&abs(a.y-b.y)<=0.0000001&&abs(a.z-b.z)<=0.0000001;
	}
	bool operator ==(const point2d& a,const double& b) {
		return a.x==0&&a.y==0&&b==0;
	}
	bool operator ==(const point3d& a,const double& b) {
		return a.x==0&&a.y==0&&a.z==0&&b==0;
	}
	bool operator !=(const point2d& a,const point2d& b) {
		return !(a==b);
	}
	bool operator !=(const point3d& a,const point3d& b) {
		return !(a==b);
	}
	// 向量加
	point2d operator +(const point2d& a,const point2d& b) {
		return point2d {a.x+b.x,a.y+b.y};
	}
	point3d operator +(const point3d& a,const point3d& b) {
		return point3d {a.x+b.x,a.y+b.y,a.z+b.z};
	}
	point2d operator +(const point2d& a,const realn& b) {
		return a+VecUnit(a)*b;
	}
	point3d operator +(const point3d& a,const realn& b) {
		return a+VecUnit(a)*b;
	}
	void point2d::operator +=(const point2d &a) {
		point2d t=(*this)+a;
		x=t.x,y=t.y;
	}
	void point3d::operator +=(const point3d &a) {
		point3d t=(*this)+a;
		x=t.x,y=t.y,z=t.z;
	}
	void point2d::operator +=(const realn &a) {
		point2d t=(*this)+a;
		x=t.x,y=t.y;
	}
	void point3d::operator +=(const realn &a) {
		point3d t=(*this)+a;
		x=t.x,y=t.y,z=t.z;
	}
	// 向量减
	point2d operator -(const point2d& a,const point2d& b) {
		return {a.x-b.x,a.y-b.y};
	}
	point3d operator -(const point3d& a,const point3d& b) {
		return {a.x-b.x,a.y-b.y,a.z-b.z};
	}
	point2d operator -(const point2d& a,const realn& b) {
		return a-VecUnit(a)*b;
	}
	point3d operator -(const point3d& a,const realn& b) {
		return a-VecUnit(a)*b;
	}
	void point2d::operator -=(const point2d &a) {
		point2d t=(*this)-a;
		x=t.x,y=t.y;
	}
	void point3d::operator -=(const point3d &a) {
		point3d t=(*this)-a;
		x=t.x,y=t.y,z=t.z;
	}
	void point2d::operator -=(const realn &a) {
		point2d t=(*this)-a;
		x=t.x,y=t.y;
	}
	void point3d::operator -=(const realn &a) {
		point3d t=(*this)-a;
		x=t.x,y=t.y,z=t.z;
	}
	// 向量乘除
	point2d operator *(const point2d& a,realn t) {
		return {a.x*t,a.y*t};
	}
	point3d operator *(const point3d& a,realn t) {
		return {a.x*t,a.y*t,a.z*t};
	}
	point2d operator *(realn t,const point2d& a) {
		return {a.x*t,a.y*t};
	}
	point3d operator *(realn t,const point3d& a) {
		return {a.x*t,a.y*t,a.z*t};
	}
	realn operator *(const point2d& a,const point2d& b) {
		return a.x*b.x+a.y*b.y;
	}
	realn operator *(const point3d& a,const point3d& b) {
		return a.x*b.x+a.y*b.y+a.z*b.z;
	}
	void point2d::operator *=(const realn &a) {
		point2d t=(*this)*a;
		x=t.x,y=t.y;
	}
	void point3d::operator *=(const realn &a) {
		point3d t=(*this)*a;
		x=t.x,y=t.y,z=t.z;
	}
	point2d operator /(const point2d& a,realn t) {
		return {a.x/t,a.y/t};
	}
	point3d operator /(const point3d& a,realn t) {
		return {a.x/t,a.y/t,a.z/t};
	}
	point2d operator /(realn t,const point2d& a) {
		return {a.x/t,a.y/t};
	}
	point3d operator /(realn t,const point3d& a) {
		return {a.x/t,a.y/t,a.z/t};
	}
	void point2d::operator /=(const realn &a) {
		point2d t=(*this)/a;
		x=t.x,y=t.y;
	}
	void point3d::operator /=(const realn &a) {
		point3d t=(*this)/a;
		x=t.x,y=t.y,z=t.z;
	}

	// 向量点积
	realn Dot(point2d a,point2d b) {
		return a.x*b.x+a.y*b.y;
	}
	realn Dot(point3d a,point3d b) {
		return a.x*b.x+a.y*b.y+a.z*b.z;
	}

	// 向量叉积
	realn Cross(point2d a,point2d b) {
		return a.x*b.y-a.y*b.x;
	}
	point3d Cross(point3d a,point3d b) {
		return point3d{a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x};
	}
	realn operator ^(const point2d& a,const point2d& b) {
		return Cross(a,b);
	}
	point3d operator ^(const point3d& a,const point3d& b) {
		return Cross(a,b);
	}

	// 转化函数
	std::string to_string(point2d a,int p=2) {
		std::stringstream ss;
//		ss.setf(fixed);
		ss.precision(p);
		ss<<"("<<a.x<<","<<a.y<<")";
		return ss.str();
	}
	std::string to_string(point3d a,int p=2) {
		std::stringstream ss;
//		ss.setf(std::ios::fixed);
		ss.precision(p);
		ss<<std::setprecision(p)<<"("<<a.x<<","<<a.y<<","<<a.z<<")";
		return ss.str();
	}
	std::string to_string(realn a,int p=2) {
		std::stringstream ss;
//		ss.setf(std::ios::fixed);
		ss.precision(p);
		ss<<std::setprecision(p)<<a;
		return ss.str();
	}
	realn r2a(realn r) {			// 弧度转角度
		return r/3.1415926*180.0;
	}
	realn a2r(realn a) {			// 角度转弧度
		return a*3.1415626/180.0;
	}
#define R2A 57.295779513082320876798154814105
#define A2R 0.01745329251994329576923690768489
#define G_PI 3.1415926535897932384626433832795

	// 输出流重载
	std::ostream& operator <<(std::ostream& out,const point2d& a) {
		out<<'('<<a.x<<','<<a.y<<')';
		return out;
	}
	std::ostream& operator <<(std::ostream& out,const point3d& a) {
		out<<'('<<a.x<<','<<a.y<<','<<a.z<<')';
		return out;
	}

	// 向量模
	realn Mod(point2d a) {
		return sqrt(a.x*a.x+a.y*a.y);
	}
	realn Mod(point3d a) {
		return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
	}
	realn Mod2(point2d a) {
		return a.x*a.x+a.y*a.y;
	}
	realn Mod2(point3d a) {
		return a.x*a.x+a.y*a.y+a.z*a.z;
	}

	// 距离函数
	realn dis(point2d a,point2d b) {
		realn dx=abs(a.x-b.x);
		realn dy=abs(a.y-b.y);
		return sqrt(dx*dx+dy*dy);
	}
	realn dis(point3d a,point3d b) {
		realn dx=abs(a.x-b.x);
		realn dy=abs(a.y-b.y);
		realn dz=abs(a.z-b.z);
		return sqrt(dx*dx+dy*dy+dz*dz);
	}
	realn disx(point2d a,point2d b) {
		return abs(a.x-b.x);
	}
	realn disx(point3d a,point3d b) {
		return abs(a.x-b.x);
	}
	realn disy(point2d a,point2d b) {
		return abs(a.y-b.y);
	}
	realn disy(point3d a,point3d b) {
		return abs(a.y-b.y);
	}
	realn disz(point3d a,point3d b) {
		return abs(a.z-b.z);
	}
	
	// 夹角
	realn VecAngle(point2d a,point2d b) {
		realn c=1.0*Dot(a,b)/Mod(a)/Mod(b);
		realn s=1.0*Cross(a,b)/Mod(a)/Mod(b);
		return atan2(s,c);
	}  
	realn VecAngle(point3d a,point3d b) {
		realn c=1.0*Dot(a,b)/Mod(a)/Mod(b);
		point3d z=Cross(a,b)/Mod(a)/Mod(b);
		realn s=1.0*Mod(z);
		if(s==0)return atan2(s,c);
		realn A,B,C,x1=0,y1=0,z1=0,x2=a.x,y2=a.y,z2=a.z,x3=b.x,y3=b.y,z3=b.y;
		A = (y3 - y1)*(z3 - z1) - (z2 -z1)*(y3 - y1);
		B = (x3 - x1)*(z2 - z1) - (x2 - x1)*(z3 - z1);
		C = (x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1);
		realn k=A*z.x+B*z.y+C*z.z;
		if(k>0)return atan2(s,c);
		return -atan2(s,c);
	}  
//	realn operator ^(const point2d& a,const point2d& b) {
//		return VecAngle(a,b);
//	}
	
	// 单位向量
	point2d VecUnit(point2d a) {
		if(Mod(a)==0)return {0,0};
		return a/(1.0*Mod(a));
	}
	point2d VecUnit(realn deg) {
		return point2d(cos(deg),sin(deg));
	}
	point3d VecUnit(point3d a) {
		if(Mod(a)==0)return {0,0,0};
		return a/(1.0*Mod(a));
	}
	
	// 投影
	point2d operator >>(const point2d& a,const point2d& b) {
		return VecUnit(b)*Dot(a,VecUnit(b));
	} 
	void point2d::operator >>=(const point2d& a) {
		*this=VecUnit(a)*Dot(*this,VecUnit(a));
	} 
	realn Shadow(point2d a,point2d b) {
		return Dot(a,VecUnit(b));
	}
	point2d ShadowV(point2d a,point2d b) {
		return VecUnit(b)*Dot(a,VecUnit(b));
	}
	point3d operator >>(const point3d& a,const point3d& b) {
		return VecUnit(b)*Dot(a,VecUnit(b));
	} 
	void point3d::operator >>=(const point3d& a) {
		*this=VecUnit(a)*Dot(*this,VecUnit(a));
	} 
	realn Shadow(point3d a,point3d b) {
		return Dot(a,VecUnit(b));
	}
	point3d ShadowV(point3d a,point3d b) {
		return VecUnit(b)*Dot(a,VecUnit(b));
	}
	
	// 向量旋转 
	point2d point2d::Rotate(realn a) {
		realn x2=x*cos(a)-y*sin(a);
		realn y2=x*sin(a)+y*cos(a);
		return point2d {x2,y2};
	}
	point3d point3d::Rotate(point3d v,realn a) {
		v=VecUnit(v);
		return (*this)*cos(a)+(v^(*this))*sin(a)+((*this)*v)*v*(1-cos(a));
	}
	
	// 绝对位置-相对位置转化
	point2d rel2abs(point2d p,point2d rfrc,realn rotate) {
		return p.Rotate(rotate)+rfrc;
	}
	point2d rel2abs(point2d p,point2d rfrc,point2d dir) {
		return p.Rotate(atan2(dir.y,dir.x))+rfrc;
	}
	point2d abs2rel(point2d p,point2d rfrc,realn rotate) {
		return (p-rfrc).Rotate(-rotate);
	}
	point2d abs2rel(point2d p,point2d rfrc,point2d dir) {
		return (p-rfrc).Rotate(-atan2(dir.y,dir.x));
	}
	
	// 对称
	point2d AxialSymmetry(point2d dir,point2d v) {
		return v.Rotate(VecAngle(v,dir)*2);
	}
	point2d CentralSymmetry(point2d o,point2d v) {
		return 2*o-v;
	}

	// 向量
	typedef point2d vector2d;
	typedef point3d vector3d;

}

#endif

// ggcc_animation
// ggcc动画库

#ifndef __GGCCANIMATION_H__
#define __GGCCANIMATION_H__

#ifdef __GGCCANIMATION_H_OLD__

#include <bits/stdc++.h>

#define MAXANIARRAY   128
#define MAXANI 1024

using namespace std;
namespace ggcc {
	
	// 计时器
	unsigned long long StartGClcok = 0;
	unsigned long long LastUpdateGClock = 0;
	bool GClockInited = false;
	long long gclock() {
		if(!GClockInited) {
			GClockInited = true;
			timespec tp;
			clock_gettime(CLOCK_REALTIME, &tp);
			StartGClcok = (unsigned long long)(tp.tv_sec) * 1000 + (unsigned long long)(tp.tv_nsec / 1000000);
			LastUpdateGClock = StartGClcok;
			return 0;
		}
		timespec tp;
		clock_gettime(CLOCK_REALTIME, &tp);
		unsigned long long now = tp.tv_sec * 1000 + tp.tv_nsec / 1000000;
		return (long long)(now - StartGClcok);
	}
	void update_gclock() {
		if(!GClockInited) {
			GClockInited = true;
			timespec tp;
			clock_gettime(CLOCK_REALTIME, &tp);
			StartGClcok = (unsigned long long)(tp.tv_sec) * 1000 + (unsigned long long)(tp.tv_nsec / 1000000);
			LastUpdateGClock = StartGClcok;
		} else {
			timespec tp;
			clock_gettime(CLOCK_REALTIME, &tp);
			unsigned long long now = tp.tv_sec * 1000 + tp.tv_nsec / 1000000;
			if(now - LastUpdateGClock > 100) StartGClcok += now - LastUpdateGClock - 16;
			LastUpdateGClock = now;
		}
	}
	
	class Animation {
		private:
			realn StartPos = 0;
			realn TargetPos = 0;
			realn NowPos;
			realn Speed = 0.5;
			int LastUpdateClock = 0;
			int MoveStyle = 0;

			realn CreateAni0(realn Start, realn End, int SpaceTime) {
				return Start + (End - Start) * (1 - pow(Speed, 1.0 * SpaceTime / 50));
			}
			realn CreateAni1(realn Start, realn End, int Spacetime) {
				realn Dis = abs(End - Start);
				realn Temp = log(Dis) / log(2);
				realn t;
				if (End > Start) {
					t = Start + Temp * (1.0 * Spacetime / Speed);
					if (t > End)t = End;
				} else {
					t = Start - Temp * (1.0 * Spacetime / Speed);
					if (t < End)t = End;
				}
				return t;
			}

		public:
			Animation(realn spos, realn tpos);
			void SetStartPos(realn Pos);
			void SetTargetPos(realn Pos);
			void SetMoveStyle(int Style);
			void SetSpeed(realn Speed);
			void GetNowPos(realn &Pos);
			realn GetNowPos();
			realn GetTargetPos();
			void Update();
	};

	Animation::Animation(realn spos = 0, realn tpos = 0) {
		StartPos = spos;
		TargetPos = tpos;
		NowPos = spos;
	}
	void Animation::SetStartPos(realn Pos) {
		StartPos = Pos;
		LastUpdateClock = gclock();
		NowPos = Pos;
	}
	void Animation::SetTargetPos(realn Pos) {
		TargetPos = Pos;
	}
	void Animation::SetMoveStyle(int Style) {
		MoveStyle = Style;
	}
	void Animation::SetSpeed(realn speed) {
		Speed = speed;
	}
	void Animation::GetNowPos(realn &Pos) {
		Pos = NowPos;
	}
	realn Animation::GetNowPos() {
		return NowPos;
	}
	realn Animation::GetTargetPos() {
		return TargetPos;
	}
	void Animation::Update() {
		if (MoveStyle == 0) {
			NowPos = CreateAni0(NowPos, TargetPos, gclock() - LastUpdateClock);
			LastUpdateClock = gclock();
		} else if (MoveStyle == 1) {
			NowPos = CreateAni1(NowPos, TargetPos, gclock() - LastUpdateClock);
			LastUpdateClock = gclock();
		}
	}

	Animation Ani[MAXANIARRAY][MAXANI];
	int NowAniArrayID = 0;
	int NowAniID = 0;

	void SetAniArray(int id) {
		NowAniArrayID = id;
	}

	void SetStartAni(int id) {
		NowAniID = id;
	}

	void UpdateAniArray() {
		for (int i = 0; i < MAXANI; i++) {
			Ani[NowAniArrayID][i].Update();
		}
	}

	realn GetAniPos(int id) {
		realn k;
		Ani[NowAniArrayID][id].GetNowPos(k);
		return k;
	}

	realn GetNextAniPos() {
		NowAniID++;
		return GetAniPos(NowAniID - 1);
	}

	void SetAniStartPos(int id, int Pos) {
		Ani[NowAniArrayID][id].SetStartPos(Pos);
	}

	void SetAniTargetPos(int id, int Pos) {
		Ani[NowAniArrayID][id].SetTargetPos(Pos);
	}

	void SetAniSpeed(int id, int speed) {
		Ani[NowAniArrayID][id].SetSpeed(speed);
	}
	void SetAniSpeed(int speed) {
		for (int i = 0; i < MAXANI; i++) {
			Ani[NowAniArrayID][i].SetSpeed(speed);
		}
	}

	void SetAniMoveStyle(int id, int Style) {
		Ani[NowAniArrayID][id].SetMoveStyle(Style);
	}
	void SetAniMoveStyle(int Style) {
		for (int i = 0; i < MAXANI; i++) {
			Ani[NowAniArrayID][i].SetMoveStyle(Style);
		}
	}

	void SetAniPos(int id, int StartPos, int TargetPos) {
		Ani[NowAniArrayID][id].SetStartPos(StartPos);
		Ani[NowAniArrayID][id].SetTargetPos(TargetPos);
	}

	void SetNextAniPos(int StartPos, int TargetPos) {
		Ani[NowAniArrayID][NowAniID].SetStartPos(StartPos);
		Ani[NowAniArrayID][NowAniID].SetTargetPos(TargetPos);
		NowAniID++;
	}

}

#endif

#ifndef __GGCCANIMATION_H_OLD__

#include <bits/stdc++.h>

#define MAXANIARRAY   128
#define MAXANI 1024

namespace ggcc {
	
	// 计时器
	unsigned long long StartGClcok = 0;
	unsigned long long LastUpdateGClock = 0;
	bool GClockInited = false;
	long long gclock() {
		if(!GClockInited) {
			GClockInited = true;
			timespec tp;
			clock_gettime(CLOCK_REALTIME, &tp);
			StartGClcok = (unsigned long long)(tp.tv_sec) * 1000 + (unsigned long long)(tp.tv_nsec / 1000000);
			LastUpdateGClock = StartGClcok;
			return 0;
		}
		timespec tp;
		clock_gettime(CLOCK_REALTIME, &tp);
		unsigned long long now = tp.tv_sec * 1000 + tp.tv_nsec / 1000000;
		return (long long)(now - StartGClcok);
	}
	void update_gclock() {
		if(!GClockInited) {
			GClockInited = true;
			timespec tp;
			clock_gettime(CLOCK_REALTIME, &tp);
			StartGClcok = (unsigned long long)(tp.tv_sec) * 1000 + (unsigned long long)(tp.tv_nsec / 1000000);
			LastUpdateGClock = StartGClcok;
		} else {
			timespec tp;
			clock_gettime(CLOCK_REALTIME, &tp);
			unsigned long long now = tp.tv_sec * 1000 + tp.tv_nsec / 1000000;
			if(now - LastUpdateGClock > 100) StartGClcok += now - LastUpdateGClock - 16;
			LastUpdateGClock = now;
		}
	}

	// 动画函数
	namespace anif {
		// 瞬间动画
		#define moment momentFun,0,1
		realn momentFun(realn x) {
			if(x<=0)return 0;
			return 1;
		}
		// 线性动画
		#define linear linearFun,0,1
		realn linearFun(realn x) {
			return x;
		}
		// 经典动画
		#define classics classicsFun,10,0
		#define classics_r classicsFun,0,10
		#define classics_d classicsdFun,0,20
		realn classicsFun(realn x) {
			return pow(1.618, x);
		}
		realn classicsdFun(realn x) {
			if(x<10)return pow(1.618, x);
			else return pow(1.618,10)*2-pow(1.618,20-x)+1;
		}
		// sin动画
		#define sine sineFun,-3.1415926/2,3.1415926/2
		realn sineFun(realn x) {
			return sin(x);
		}
		// tan动画
		#define tanf tanFun,-1.35, 1.35
		realn tanFun(realn x) {
			return sin(x) / cos(x);
		}
		// tanh动画
		#define tanh tanhFun,-2.5, 2.5
		realn tanhFun(realn x) {
			return (exp(x)-exp(-x)) / (exp(x)+exp(-x));
		}
		// 回弹动画（阻力5）
		#define bounce bounceFun,-8.9726,0
		#define bounce1 bounceFun,-8.9726,0
		realn bounceFun(realn x) {
			return -7.0 / 51 * sqrt(51) * exp(-7.0 / 10 * x) * sin(1.0 / 10 * sqrt(51) * x) - exp(-7.0 / 10 * x) * cos(1.0 / 10 * sqrt(51) * x);
		}
		// 回弹动画（阻力4）
		#define bounce2 bounce2Fun,-8.2645,0
		realn bounce2Fun(realn x) {
			return -13.0 / 231 * sqrt(231) * exp(-13.0 / 20 * x) * sin(1.0 / 20 * sqrt(231) * x) - exp(-13.0 / 20 * x) * cos(1.0 / 20 * sqrt(231) * x);
		}
		// 回弹动画（阻力3）
		#define bounce3 bounce3Fun,-7.9188,0
		realn bounce3Fun(realn x) {
			return -3.0 / 4 * exp(-3.0 / 5 * x) * sin(4.0 / 5 * x) - exp(-3.0 / 5 * x) * cos(4.0 / 5 * x);
		}
		// 回弹动画（阻力2）
		#define bounce4 bounce4Fun,-7.5220,0
		realn bounce4Fun(realn x) {
			return -11.0 / 93 * sqrt(31) * exp(-11.0 / 20 * x) * sin(3.0 / 20 * sqrt(31) * x) - exp(-11.0 / 20 * x) * cos(3.0 / 20 * sqrt(31) * x);
		}
		// 回弹动画（阻力1）
		#define bounce5 bounce5Fun,-7.3448,0
		realn bounce5Fun(realn x) {
			return -1.0 / 3 * sqrt(3) * exp(-1.0 / 2 * x) * sin(1.0 / 2 * sqrt(3) * x) - exp(-1.0 / 2 * x) * cos(1.0 / 2 * sqrt(3) * x);
		}
	}

	int AniTotal = 0;
	int AniEnabled = 1;
	bool ContinuityCheck = true;
	
	class Animation {
		private:
			realn StartPos = 0;
			realn TargetPos = 0;
			int StartTime = 0;
			int Duration = 500;
			int RepeatDelay = 0;
			int ReturnDelay = 0;
			realn NowPos;
			realn (*Fun)(realn) = anif::classicsFun;
			realn FunStart = 10;
			realn FunEnd = 0;
			bool IsStopped = false;
			bool Repeat_ = false;
			bool Return_ = false;
			bool Returned = false;

		public:
			~Animation() {AniTotal--;}
			Animation();
			Animation(realn);
			Animation(realn, realn);
		
			Animation& SetStartPos(realn);
			Animation& SetTargetPos(realn, int);
			Animation& SetMoveStyle(realn (*fun)(realn), realn, realn);
			Animation& SetDuration(int);
			realn GetNowPos();
			realn GetTargetPos();
			realn GetStartPos();
			int GetStartTime();
			bool IsRunning();
			Animation& Stop();
			Animation& Pause();
			Animation& Continue();
			Animation& Update();
			Animation& Reset();
			Animation& Repeat(bool, int);
			Animation& Return(bool, int);
			Animation& Goto(realn);

			inline Animation& ssp(realn pos) {return SetStartPos(pos);}
			inline Animation& stp(realn pos, int delay = 0) {return SetTargetPos(pos, delay);}
			inline Animation& sms(realn (*fun)(realn), realn st, realn end) {return SetMoveStyle(fun, st, end);}
			inline Animation& sd(int duration) {return SetDuration(duration);}
			inline realn gp(int time) {return GetPos(time);}
			inline realn gnp() {return GetNowPos();}
			inline realn gsp() {return GetStartPos();}
			inline realn gtp() {return GetTargetPos();}
			inline int gst() {return GetStartTime();}
			inline bool is_run() {return IsRunning();}
			inline Animation& stop() {return Stop();}
			inline Animation& pause() {return Pause();}
			inline Animation& cont() {return Continue();}
			inline Animation& update() {return Update();}
			inline Animation& reset() {return Reset();}
			inline Animation& repeat(bool b, int delay = 0) {return Repeat(b, delay);}
			inline Animation& retn(bool b, int delay = 0) {return Return(b, delay);}
			inline Animation& gt(realn pos) {return Goto(pos);};
		
			realn AniFun(realn x) {
				if(x<0)return StartPos;
				if(x>Duration)return TargetPos;
				realn dtf = FunEnd - FunStart;
				realn l = Fun(FunEnd) - Fun(FunStart);
				realn zoom = 1.0 * (TargetPos - StartPos) / l;
				realn dt = x / Duration * dtf;
				return (Fun(FunStart + dt) - Fun(FunStart)) * zoom + StartPos;
			}
			realn GetPos(realn x) {
				x-=StartTime;
				if(Repeat_&&Return_) {
					x-=floor(x/(Duration*2+RepeatDelay+ReturnDelay))*(Duration*2+RepeatDelay+ReturnDelay);
					if(x<Duration+ReturnDelay)return AniFun(x);
					else return AniFun((Duration*2+ReturnDelay)-x);
				} else if(Repeat_&&!Return_) {
					x-=floor(x/(Duration+RepeatDelay))*(Duration+RepeatDelay);
					return AniFun(x);
				} else if(!Repeat_&&Return_) {
					if(x<Duration)return AniFun(x);
					else if(x<Duration*2+ReturnDelay)return AniFun(2*Duration+ReturnDelay-x);
				} else {
					return AniFun(x);
				}
			}
	};

	Animation::Animation() {
		NowPos = StartPos = TargetPos = 0;
		StartTime = gclock();
		AniTotal++;
	}
	Animation::Animation(realn pos) {
		NowPos = StartPos = TargetPos = pos;
		StartTime = gclock();
		AniTotal++;
	}
	Animation::Animation(realn spos, realn tpos) {
		NowPos = StartPos = spos;
		TargetPos = tpos;
		StartTime = gclock();
		AniTotal++;
	}
	Animation& Animation::SetStartPos(realn pos) {
		StartPos = NowPos = TargetPos = pos;
		StartTime = gclock();
		return *this;
	}
	Animation& Animation::SetTargetPos(realn pos, int delay = 0) {
		if (pos == TargetPos)return *this;
		StartPos = NowPos;
		TargetPos = pos;
		StartTime = gclock() + delay;
		return *this;
	}
	Animation& Animation::SetMoveStyle(realn (*fun)(realn), realn start, realn end) {
		Fun = fun;
		FunStart = start;
		FunEnd = end;
		return *this;
	}
	Animation& Animation::SetDuration(int time) {
		Duration = time;
		return *this;
	}
	realn Animation::GetNowPos() {
		if(AniEnabled==0)return TargetPos;
		return NowPos;
	}
	realn Animation::GetTargetPos() {
		return TargetPos;
	}
	int Animation::GetStartTime() {
		return StartTime;
	}
	realn Animation::GetStartPos() {
		return StartPos;
	}
	bool Animation::IsRunning() {
		if (gnp()==gtp())return false;
		else return true;
	}
	Animation& Animation::Pause() {
		IsStopped = true;
		return *this;
	}
	Animation& Animation::Continue() {
		IsStopped = false;
		return *this;
	}
	Animation& Animation::Update() {
		int NowTime = gclock();
		realn dtf = FunEnd - FunStart;
		if (NowTime < StartTime) return *this;
		if (NowTime > StartTime + Duration) {
			if (Repeat_) {
				if(!Return_||Returned) {
					Returned=false;
					NowPos = StartPos;
					NowTime = gclock();
					StartTime += Duration + RepeatDelay;
				}
			}
			if(Return_) {
				NowPos = TargetPos;
				realn t=StartPos;
				StartPos=TargetPos;
				TargetPos=t;
				NowTime = gclock();
				StartTime += Duration + ReturnDelay;
				Returned=true;
			}
			else NowPos = TargetPos;
			return *this;
		}
		if (AniEnabled == 1) {
			realn l = Fun(FunEnd) - Fun(FunStart);
			realn zoom = 1.0 * (TargetPos - StartPos) / l;
			realn dt = 1.0 * (NowTime - StartTime) / Duration * dtf;
			NowPos = (Fun(FunStart + dt) - Fun(FunStart)) * zoom + StartPos;
		} else if (AniEnabled == 0) {
			NowPos = TargetPos;
		} else if (AniEnabled == 2) {
			realn dtf = 1;
			realn l = 1;
			realn zoom = 1.0 * (TargetPos - StartPos) / l;
			realn dt = 1.0 * (NowTime - StartTime) / Duration * dtf;
			NowPos = (FunStart + dt - FunStart) * zoom + StartPos;
		}
		return *this;
	}
	Animation& Animation::Reset() {
		NowPos = StartPos;
		StartTime = gclock();
		return *this;
	}
	Animation& Animation::Repeat(bool b, int delay = 0) {
		Repeat_ = b;
		RepeatDelay = delay;
		return *this;
	}
	Animation& Animation::Return(bool b, int delay = 0) {
		Return_ = b;
		if(Returned) {
			NowPos = TargetPos;
			realn t=StartPos;
			StartPos=TargetPos;
			TargetPos=t;
			Returned = false;
		}
		ReturnDelay = delay;
		return *this;
	}
	Animation& Animation::Stop() {
		Update();
		TargetPos=NowPos;
		StartPos=NowPos;
		return *this;
	}
	Animation& Animation::Goto(realn pos) {
		TargetPos=pos;
		StartPos=pos;
		NowPos=pos;
		StartTime=gclock()-Duration;
		return *this;
	}

};

#endif
#endif