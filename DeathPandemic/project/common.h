#pragma once
//���W�̂��߂̍\����
struct POSITION 
{
	double x;
	double y;
};

struct CIRCLE {//�~����銴��
	int x, y; // ���S���W
	int r; // ���a
};

// �~�Ɖ~�̓����蔻����s��
// �������Ă����true��Ԃ�
bool CircleCollision1(CIRCLE c1, CIRCLE c2);
bool CircleCollision2(CIRCLE c3, CIRCLE c4);
