package castle;

import java.util.HashMap;

public class Room {
    private String description;
    private HashMap<String, Room> exits = new HashMap<String,Room>();		
//    private Room northExit;
//    private Room southExit;
//    private Room eastExit;
//    private Room westExit;
    public void setExit(String dir, Room room){
    	exits.put(dir, room);
    }
    
    public Room nextRoom(String direction){
    	return exits.get(direction);
        }
    
    
    public void printExit(){
    	for(String dir: exits.keySet()){
    		if(dir != null){
                System.out.print(dir+" ");
    		}
    	}
//        if(this.northExit != null)
//        if(this.eastExit != null)
//            System.out.print("east ");
//        if(this.southExit != null)
//            System.out.print("south ");
//        if(this.westExit != null)
//            System.out.print("west ");
    }
    
    public Room(String description) 
    {
        this.description = description;
    }

    

    @Override
    public String toString()
    {
        return description;
    }
}
