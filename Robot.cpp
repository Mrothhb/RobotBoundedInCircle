class Solution {
public:
    bool isRobotBounded(string instructions) {
        
        char curDir = 'N';
        vector< pair <int,int> > pos; 
        pos.push_back( make_pair(0,0) ); 
        
        if (instructions.find('G') == std::string::npos){
            return true;
        }
                   
        for(int i = 0; i<instructions.length();i++){
            if( instructions[i] == 'G'){
                if( curDir == 'N'){
                    pos[0].second+=1;
                }
                else if( curDir == 'S'){
                    pos[0].second-=1;
                }
                else if( curDir == 'E'){
                    pos[0].first+=1;
                }
                else if( curDir == 'W'){
                    pos[0].first-=1;
                }
            }
            else if( curDir == 'N' && instructions[i]=='L'){
                curDir = 'W';
            }
            else if( curDir == 'N' && instructions[i] == 'R'){
                curDir = 'E';            
            }
            else if( curDir == 'S' && instructions[i] == 'L'){
                curDir = 'E';
            }
            else if( curDir == 'S' && instructions[i] == 'R'){
                curDir = 'W';
            }
            else if( curDir == 'E' && instructions[i] == 'L'){
                curDir = 'N';
            }
            else if( curDir == 'E' && instructions[i] == 'R'){
                curDir = 'S';
            }
            else if( curDir == 'W' && instructions[i] == 'L'){
                curDir = 'S';
            }
            else if( curDir == 'W' && instructions[i] == 'R'){
                curDir = 'N';
            }
        }
        
        if( pos[0].first == 0 && pos[0].second == 0 ){
            return true;
        }
        
        if( curDir == 'N'){
            return false;
        }
        
        return true;
    }
};
