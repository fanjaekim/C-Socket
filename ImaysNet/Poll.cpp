#include "stdafx.h"
#include "Poll.h"

// fdArray�� fdArrayLength�� ����Ű�� �迭�� ���� �� �ϳ� �̻��� �̺�Ʈ�� ����ų ������ ��ٸ�.
// timeOutMs�� �ִ� ��� �ð��� �и��� ������ ��ٸ��� ���̴�.
int Poll(PollFD* fdArray, int fdArrayLength, int timeOutMs)
{
	static_assert(sizeof(fdArray[0]) == sizeof(fdArray[0].m_pollfd), ""); // �̸� �������� ���ϸ� PollFD�� virtual �Լ� �� �ٸ� ����� ��. �̷��� ��� PollFD�κ��� ����Ƽ�� �迭���� ���縦 ���ִ� ���� ������ �����ؾ� �Ѵ�.
#ifdef _WIN32
	return ::WSAPoll((WSAPOLLFD*)fdArray, fdArrayLength, timeOutMs);
#else
	return ::poll((pollfd*)fdArray, fdArrayLength, timeOutMs);
#endif
}