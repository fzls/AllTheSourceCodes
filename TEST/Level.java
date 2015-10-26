package bab2;

public class Level {
	public static void main(String args[]) {
		short newGrade, grade;
		grade = Short.parseShort(args[0]);
		switch (grade / 10) {
		case 10:
		case 9: newGrade = 1; break;
		case 8: newGrade = 2; break;
		case 7: newGrade = 3; break;
		case 6: newGrade = 4; break;
		default: newGrade = 5;
		}
		System.out.print(grade);
		switch (newGrade) {
		case 1: System.out.println(",ÓÅÐã"); break;
		case 2: System.out.println(",Á¼ºÃ"); break;
		case 3: System.out.println(",ÖÐµÈ"); break;
		case 4: System.out.println(",¼°¸ñ"); break;
		case 5: System.out.println(",²»¼°¸ñ"); break;
		}
	}

}
