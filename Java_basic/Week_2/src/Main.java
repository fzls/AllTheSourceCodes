
public class Main {


	public static void main(String[] args) throws InterruptedException {
		java.util.Scanner in = new java.util.Scanner(System.in);
		Clock clock = new Clock(in.nextInt(), in.nextInt(), in.nextInt());
//		for(int i=100;i>0;i++){
			clock.tick();
			System.out.println(clock.toString());
//			Thread.sleep(50);
//		}
		in.close();
	}
}
class Display {
	private int value = 0;
	private int limit = 0;
	int getValue() {
		return value;
	}
	Display(int limit) {
		this.limit = limit;
	}
	public void setValue(int value) {
		this.value = value;
	}
	boolean increase() {
		boolean flag = false;
		value++;
		if (value == limit) {
			value = 0;
			flag = true;
		}
		return flag;
	}
}

class Clock {
	private Display hour = new Display(24);
	private Display minute = new Display(60);
	private int second = 0;
	public Clock(int hour, int minute, int second) {
		this.hour.setValue(hour);
		this.minute.setValue(minute);
		this.second = second;

	}
	public void tick() {
			second++;
			if (second == 60) {
				second = 0;
				if (minute.increase()) {
					hour.increase();
				}
			}

	}
	public String toString() {
		return String.format("%02d:%02d:%02d", hour.getValue(), minute.getValue(), second );

	}
}
