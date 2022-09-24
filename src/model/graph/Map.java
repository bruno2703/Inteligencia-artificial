package src.model.graph;

import java.util.ArrayList;

public class Map {
    private ArrayList<State> listOfStates;
    
    public Map(String[] cityNames){
        this.listOfStates = new ArrayList<State>();
        for(int k=0; k<cityNames.length; k++){
            listOfStates.add(new State(cityNames[k]));
        }
    }
    public boolean initializeAdjacentList(String cityName, int[] costList, String[] adjacencies){
        boolean validCity = false;
        int currentIndex = 0;
        for(int k=0; k<this.listOfStates.size(); k++){
            if(this.listOfStates.get(k).getCityName().equals(cityName)){
                validCity = true;
                currentIndex = k;
                break;
            }
        }
        if(validCity){
            for(int k=0; k<this.listOfStates.size(); k++){
                for(int j=0; j<adjacencies.length; j++){
                    if(this.listOfStates.get(k).getCityName().equals(adjacencies[j])){
                        this.listOfStates.get(currentIndex).getAdjacentList().add(new Transition(this.listOfStates.get(k), costList[j]));
                        break;
                    }
                }
            }
        }
        return validCity;
    }
    public ArrayList<State> getListOfStates(){
        return this.listOfStates;
    }
    public String toString(){
        String s = "";
        for(int k=0; k<listOfStates.size(); k++){
            s+=listOfStates.get(k).toString()+"\n";
        }
        return s;
    }
}
