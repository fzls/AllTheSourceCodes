class Time {
	public int hour;
	private int minute;
	private int second;

	public Time() {
		setTime(0, 0, 0);
	}

	public void setTime(int hh, int mm, int ss) {
		hour = ((hh >= 0 && hh < 24) ? hh : 0);
		minute = ((mm >= 0 && mm < 60) ? mm : 0);
		second = ((ss >= 0 && ss < 60) ? ss : 0);
	}

	public String toString() {
		return (hour + ":" +
		        (minute < 10 ? "0" : "") + minute + ":" +
		        (second < 10 ? "0" : "") + second
		       );
	}
	public static void main(String args[]) {
		Time time = new Time();
		time.hour = 11;
		System.out.println(time);
	}
}