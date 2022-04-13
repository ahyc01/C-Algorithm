class Solution {
	public String solution(int[] numbers, String hand) {
		String answer = "";
		int h_and = 0; //주로쓰는 손
		int R_point = 30; // 오른손가락 위치
		int L_point = 32; //왼손가락 위치
		int point = 0; //현재 손가락위치
		int N_point = 0; //다음 손가락위치
		int r_x = 0, l_x = 0;

		int keypad[][] = { { 1,2,3 }, //키패드
		{ 4,5,6 },
		{ 7,8,9 },
		{ 10,0,11 } };

		int keypad_point[][] = { { 0,1,2 }, //키패드위치
		{ 10,11,12 },
		{ 20,21,22 },
		{ 30,31,32 } };

		int L_hand[] = { 1,4,7,10 };
		int R_hand[] = { 3,6,9,12 };

		if (hand.equals("right")) { // 주로쓰는 손 확인
			h_and = 1;
		}

		for (int num = 0; num < numbers.length; num++) {  //시작     

			for (int i = 0; i<4; i++) {
				for (int j = 0; j<3; j++) {
					if (keypad[i][j] == numbers[num]) {
						N_point = keypad_point[i][j]; //눌러야하는 번호 위치 확인
					}
				}
			}
			System.out.printf("num : %d\n", numbers[num]);
			System.out.printf("%d, %d, %d\n", L_point, R_point, N_point);

			for (int x = 0; x< L_hand.length; x++) {
				System.out.printf(" L : %d R : %d\n", L_hand[x], R_hand[x]);
				if (L_hand[x] == numbers[num]) { //먼저 양손에 가까운지 위치 확인
					answer += "L";
					L_point = N_point;
					point = N_point;
					break;
				}
				else if (R_hand[x] == numbers[num]) {
					answer += "R";
					R_point = N_point;
					point = N_point;
					break;
				}
				else if (x == L_hand.length - 1) { //가운데키패드라면 거리계산

					if (L_point / 10 <= N_point / 10) { //왼손가락 거리계산
						if (L_point % 10 <= N_point % 10) {
							l_x = (N_point / 10) - (L_point / 10) + (N_point % 10) - (L_point % 10);
						}
						else {
							System.out.printf("2\n");
							l_x = (N_point / 10) - (L_point / 10) + (L_point % 10) - (N_point % 10);
						}
					}
					else {
						if (L_point % 10 <= N_point % 10)
							l_x = (L_point / 10) - (N_point / 10) + (N_point % 10) - (L_point % 10);
						else
							l_x = (L_point / 10) - (N_point / 10) + (L_point % 10) - (N_point % 10);
					}

					System.out.printf("l_x : %d", l_x);

					if (R_point / 10 <= N_point / 10) { //오른손가락 거리계산
						if (R_point % 10 <= N_point % 10)
							r_x = (N_point / 10) - (R_point / 10) + (N_point % 10) - (R_point % 10);
						else
							r_x = (N_point / 10) - (R_point / 10) + (R_point % 10) - (N_point % 10);
					}
					else {
						if (R_point % 10 <= N_point % 10)
							r_x = (R_point / 10) - (N_point / 10) + (N_point % 10) - (R_point % 10);
						else
							r_x = (R_point / 10) - (N_point / 10) + (R_point % 10) - (N_point % 10);
					}
					System.out.printf(" r_x : %d\n", r_x);


					if (l_x<r_x) { //거리비교
						answer += "L";
						L_point = N_point;
						point = N_point;
						break;
					}
					else if (l_x>r_x) {
						answer += "R";
						R_point = N_point;
						point = N_point;
						break;
					}
					else if (l_x == r_x) {
						if (h_and == 0) {
							answer += "L";
							L_point = N_point;
							point = N_point;
							break;
						}
						else {
							answer += "R";
							R_point = N_point;
							point = N_point;
							break;
						}
					}
				}
			}
		}
		return answer;
	}
}