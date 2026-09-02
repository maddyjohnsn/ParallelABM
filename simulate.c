
//will go through the world updating agent
//
//

void updateInfection(Agent* agents, int numAgents){

	//want to go through, check how many infection counters an agent had
	//I actually don't think that an agent shoudl become infected in the middle of the day... infections are gradual?? 
	
	for (int i = 0; i < numAgents; i++) {
        	if (agents[i].isInfected) continue;

		int infectedContacts = 0;
        	for (int j = 0; j < numAgents; j++) {
            		if (agents[i].encounters[j] > 0 && agents[j].isInfected) {
                		infectedContacts++;
            		}
        	}

		//want it to be 3 if agent is not predisposed and 2 if yes
        	if (infectedContacts >= 3) {
            		agents[i].isInfected = true;
        
			
		}


	}

}


