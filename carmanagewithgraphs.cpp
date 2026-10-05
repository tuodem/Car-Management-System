//Prorgam is to simulate how a car inventory would work by using linked lists, vectors and arrays
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>

using namespace std;
template <typename T>

class Node{
    public:
        T data;
        Node<T> *next;

        Node(T val){
            data = val;
            next = NULL;
        }
};
class Car {
private:
    string brandModel;   // e.g., "Toyota_Camry"
    string dateSold;     // e.g., "06-28-2026"

public:
    Car(){}
    //stores the data for each car model and date each car was bought by the dealership
    Car(string bm, string ds) {
        brandModel = bm;
        dateSold = ds;
    }
    //gets the brand model data stored in the class
    string getBrandModel() const {
        return brandModel;
    }
    //gets the date the car was bought by the dealership
    string getDateSold() const {
        return dateSold;
    }
    //sets the brand model data to be stored in the class
    void setBrandModel(string bm) {
        brandModel = bm;
    }
    //sets the date that the car is bought by the dealership
    void setDateSold(string ds) {
        dateSold = ds;
    }
    //prints the brand model
    void print() const {
        cout << brandModel << endl;
    }
};

template <typename T>
//class to track the dates of cars being sold
class CarBought{
    private:
        Node<T> *head;
        Node<T> *tail;

    public:
        CarBought(){
            head = tail = NULL;
        
        }
        //used push front to add values to the front usual linked list method
        void push_front(T val){
            Node<T> *newNode = new Node<T>(val);
            if(head == NULL){
                head = tail = newNode;
                return;
            }
            else{

                newNode->next = head;
                head = newNode;
            }
        }
        //push_back used for linked lists as its a method commonly used
        void push_back(T val){
            Node<T> *newNode = new Node<T>(val);
            if(head == NULL){
                head = tail = newNode;
                return;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }
            
        }
        //pop_front to remove values at the front of list
        void pop_front(){
            if(head == NULL){
                cout<<"list is empty"<<endl;
                return;
            }
            Node<T> *temp = head;
            head = head ->next;
            delete temp;
            
        }
        //pop_back used to remove values at the end
        void pop_back(){
            if(head == NULL){
                cout<<"list is empty";
                return;
            }
            if(head == tail){
                delete head;
                head = tail = NULL;
                return;
            }
            Node<T> *temp = head;
            while(temp->next != tail){
                temp=temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = NULL;
        }
        //prints all values in linked list
        void printll(){
            Node <T>*temp = head;
            int count = 1;
            cout<<"Dates for Each Car numbered:\n";
            while(temp!=NULL){
                cout<<count<<". "<<temp->data<<endl;
                temp = temp->next;
                count++;
            }
        }
        //deletes values at specific spots in the linked list
        void deleteAt(int pos){
            //if the value is at the first position it deletes the value
            if(pos==1){
                Node<T> *temp = head;
                head = head->next;
                delete temp;
                if(head == NULL){
                    tail = NULL;
      
                }
                return;
            }


            Node <T>*prev = head;
            //checks to see if pos goes out of range
            for(int i = 1;i<pos-1;i++){
                if(prev->next == NULL){
                    cout<<"Position is out of range"<<endl;
                    return;
                }
                prev = prev->next;

            }

            Node <T>*target = prev->next;
            if(target == NULL){
                cout<<"Position is out of range"<<endl;
                return;
            }
            //updates the values to not break the linked list
            prev->next = target->next;
            if (target == tail){
                tail = prev;
            }
            //deletes the value that you are looking for
            delete target;

        }
        void update(T date, int pos){
            Node<T> *cur = head;
            //increments the linked list to find the value to be updated
            for(int i =1;i<pos&&cur!=NULL;i++){
                cur=cur->next;
            }
            //updates the value 
            if(cur != NULL){
                cur->data = date;
            }
            
        }
        
};
template <typename T>

class StackOperations{
    private:
    //creates the node for the data at the top of stack
        Node<T> *topNode;

    public:
        StackOperations(){
            topNode = NULL;
        }
        //push used for stacks to add values into the stack
        void push(T val){
            Node<T> *newNode = new Node<T>(val);
            newNode->next = topNode;
            topNode = newNode;
            
        }
    
        //pop used to remove values at the end
        void pop(){
            if(topNode == NULL){
                cout<<"list is empty";
                return;
            }
            Node <T>*temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
        //prints the value at the most recent value added
        void top(){
            if(topNode == NULL){
                cout<<"No history Recorded"<<endl;
                return;
            }
            return topNode->data;

        }
        //prints everything in the stack
        void display(){
            Node <T>*temp = topNode;
            while(temp!=NULL){
                cout<<temp->data<<endl;
                temp = temp->next;
            }
        }
        //checks if stack is empty
        bool empty(){
            if(topNode==NULL){
                return true;
            }
            return false;
        }
        //clears everything in the stack
        void clear(){
            if(topNode == NULL){
                cout<<"Empty"<<endl;
            }
            while(!empty()){
                pop();
            }
        }
        
    
    
};

template <typename T>
class DetailQueue{
    private:

        vector<T> clean;
    

    public:
        //adds vehicles to the queue
        void enqueue(T val){
            clean.push_back(val);

        }
        //deletes vehicles from the queue
        void dequeue(){
            if(!clean.empty()){
                clean.erase(clean.begin());
            }
            else{
                cout<<"Queue is empty"<<endl;
            }
            
        }
        //checks what the value is at the front of queue
        T front(){

            if(!clean.empty()){
            
                return clean[0];
            }
            cout<<"Vehicle doesn't exist in inventory"<<endl;
            return T{};     
        }
        //checks if the queue is empty
        bool empty(){
            return clean.empty();
        }
        //prints whats in the queue
        void display(){
            for(int i = 0;i<clean.size();i++){
                cout<<clean[i]<<endl;
            }

        }


};
template <typename T>
class ServiceQueue{
    
    private:
        T *arr;
        int front;
        int rear;
        int size;

    public:
        ServiceQueue(){
            size = 8;
            front = -1;
            rear = -1;
            arr = new T[size];
        }
        //checks if circular queue array is empty
        bool isempty(){
            return front == -1;
        }
        //checks if the circular queue is full
        int isFull(){
            if((rear+1)%8==front){
                return 1;
            }
            return 0;
        }
        //adds values to the circular queue
        void enqueue(T val){
            if(isFull()){
                cout<<"Service Shop Line is full"<<endl;
                return;
            }
            if(isempty()){
                front = rear = 0;
            }
            else{
                rear = (rear+1)%size;
                
            }
            arr[rear] = val;
        }
        //removes values from the circular queue
        void dequeue(){
            if(isempty()){
                cout<<"Service shop line is empty"<<endl;
                return;
            }
            if(front==rear){
                front = rear = -1;
            }
            else{
                front = (front+1)%size;
                size--;
            }
        }
        //prints the values in the circular queue
        void display(){
            //checks if the queue is empty to prevent the array from printing infinitely
            if(isempty()){
                cout<<"Service Line is empty"<<endl;
                return;
            }
            //prints the array after making sure the front of array is less than or equal to rear
            if(front<=rear){
                for(int i = front; i <= rear;i++){
                    cout<<arr[i]<<endl;
                }
            }
            //checks for the wrap around 
            else{
                for(int i = front; i < size;i++){
                    cout<<arr[i]<<endl;
                }
                for(int i = 0; i <= rear;i++){
                    cout<<arr[i]<<endl;
                }
            }
        }


    
};

class RecommendationGraph{

    private:
        vector<vector<string> > rec;
        vector<int> BrandRating;
        vector<vector<int> > weight;
        int numVertices;
    public:
        RecommendationGraph(int size){
            BrandRating.resize(size,0);
            rec.resize(size);
            numVertices = size;
            weight.resize(size, vector<int>(numVertices, INT_MAX));
        }
        //adds the vertex
        void addVertex(){
            rec.push_back(vector<string>());
            numVertices++;
            weight.resize(numVertices);
            for(int i=0;i<numVertices;i++){
                weight[i].resize(numVertices,INT_MAX);
            }
            BrandRating.resize(numVertices, 0);
        }
        //removes the vertex
        void removeVertex(int targetIdx){
            if(targetIdx<0||targetIdx>=rec.size()){
                return;
            }
            rec.erase(rec.begin()+targetIdx);
        }
        //prints the graph
        void displayGraph(){
            //displays the data in our graph
            cout << "Car Brand Graph:\n\n";

            for (int row = 0; row < rec.size(); row++) {
                cout << rec[row][0] << ":\n";   // Brand name
                //prevents the last part of the graph from reprinting the Brand names again
                for (int col = 1; col < (rec[row].size()-2); col++) {
                    cout << "   " << rec[row][col];

                    if (col < rec[row].size() - 1) {
                        cout << " -> ";
                    }
                }

                cout << "\n\n";
            }
        }
        //connects edges to vertexes
        void addEdge(int source, string target){
            if(source<rec.size()){
                rec[source].push_back(target);
            }
            else{
                cout<<"Error Vertex "<<source<<"doesn't exist"<<endl;
                
            }
        }
        //searches for the vertex by looking for the car brand connected to it
        bool searchVertex(int startNode,string targetBrand){
            //uses breadth first search
            int targetNode = -1;
            for(int i = 0; i<rec.size();i++){
                for(int j =0;j<rec[i].size();j++){
                    if(rec[i][j] == targetBrand){
                        targetNode = i;
                        break;
                    }
                }
            }
            if(targetNode == -1){
                return false;
            }
            if(targetNode == startNode){
                return true;
            }
            vector<bool> visited(rec.size(), false);
            queue<int> searchq;

            searchq.push(startNode);
            visited[startNode] = true;
            
            while(!searchq.empty()){
                int currentIndex = searchq.front();
                searchq.pop();
                
                if(rec[currentIndex][0] == targetBrand){
                    return true;
                }

                for(int i = 0; i<rec[currentIndex].size();i++){
                    string neighbor = rec[currentIndex][i];
                    int neighboridx = -1;
                    for(int j = 0; j<numVertices;j++){
                        if(rec[j][0] == neighbor){
                            neighboridx = j;
                            break;
                        }
                    }
                    if(neighboridx != -1 && !visited[neighboridx]){
                        visited[neighboridx] = true;
                        searchq.push(neighboridx);
                    }
                }

            }
           
            return false;
 
        }
        //used for visiting the neighbor nodes with depth first search to find the make of the car
        bool searchEdge(int startNode, string targetMake,vector<bool> &visited){

            
            if(visited[startNode]) return false;
            visited[startNode] = true;

           for (int i = 1; i < rec[startNode].size(); i++) {
                if (rec[startNode][i] == targetMake)
                    return true;
            }
            for(int i =1;i<rec[startNode].size();++i){
                string neighbor = rec[startNode][i];
                int neighboridx = -1;


                for(int j = 1;j<rec.size();++j){
                    if(rec[j][0]==neighbor){
                        neighboridx = j;
                        break;
                    }

                }
                if(neighboridx == -1){
                    continue;
                }
                if(!visited[neighboridx]){
                    if(searchEdge(neighboridx,targetMake,visited)){
                        return true;
                    }
                }

            }
            return false;

        }
        //used for recursively checking the neighbors and remembering the visited nodes
        bool searchEdge(int startNode, string targetMake){
            vector<bool> visited(rec.size(), false);
            return searchEdge(startNode, targetMake, visited);
        }
        //gives each brand a rating
        void setBrandRating(int idx, int rating){
            if(idx >= 0 && idx < BrandRating.size()){
                BrandRating[idx] = rating;
            }
        }
        //adds the brand to an edge for prims
        void addBrandEdge(int from, int to){
            int w = BrandRating[to]+BrandRating[from];
            // if(from >= 0 && from < numVertices && to >= 0 && to < numVertices){
            weight[from][to] = w;   // weight = rating of destination brand
            weight[to][from] = w; // undirected graph
            //}
        }
        //prims algorithm to find the ratings of each brand
        vector<int> primMST(int start){
            //stores tehe minimum weight edges
            vector<int> key(numVertices, INT_MAX);
            //keeps what has been visited
            vector<bool> inMST(numVertices, false);
            vector<int> parent(numVertices, -1);

            key[start] = 0;

            for(int count = 0; count < numVertices - 1; count++){
                int u = -1;

                for(int i = 0; i < numVertices; i++){
                    //finds the vertex with the minimum value
                    if(!inMST[i] && (u == -1 || key[i] < key[u])){
                        u = i;
                    }
                }

                inMST[u] = true;

                for(int v = 0; v < numVertices; v++){
                    //connects the vertex to the minimum spanning tree(prim)
                    if(weight[u][v] < key[v] && !inMST[v]){
                        key[v] = weight[u][v];
                        parent[v] = u;
                    }
                }
            }

            return parent;
        }
        //prints prims
    
        void printMST(const vector<int>& parent){
            int root = -1;

            // Find root (parent == -1)
            for(int i = 0; i < parent.size(); i++){
                if(parent[i] == -1){
                    root = i;
                    break;
                }
            }

            vector<int> order;
            int current = root;

            // Follow MST chain downward
            while(true){
                order.push_back(current);

                bool found = false;
                for(int i = 0; i < parent.size(); i++){
                    if(parent[i] == current){
                        current = i;
                        found = true;
                        break;
                    }
                }

                if(!found) break;
            }

            // Prints MST
            cout << "Recommended Brands (Prim):\n";
            for(int i = 0; i < order.size(); i++){
                cout << rec[order[i]][0] << " (Rating " << BrandRating[order[i]] << ")\n";
                if(i < order.size() - 1){
                    cout << "   |\n";
                    cout << "   v\n";
                }
            }
        }



};

int main(){
    CarBought<string> ll;
    vector<Car> car;
    StackOperations<string> history;
    DetailQueue<string> cleancar;
    ServiceQueue<string> service;
    RecommendationGraph carRec(0);
    string brandModel;
    string dateSold;
    string name;
    string findCar;
    string arr[5];
    int displayCount = 0;
    int num;

    carRec.addVertex();
    carRec.addVertex();
    carRec.addVertex();
    //seting the ratings for each brand using prims algorithm
    carRec.setBrandRating(0, 5); // Toyota
    carRec.setBrandRating(1, 5); // Honda
    carRec.setBrandRating(2, 4); // Lexus
    //connects the brands to each other for prims 
    carRec.addBrandEdge(0, 1);   // Toyota <-> Honda
    carRec.addBrandEdge(0, 2);   // Toyota <-> Lexus
    carRec.addBrandEdge(1, 2);   // Honda <-> Lexus

    //Toyota Vertex
    carRec.addEdge(0,"Toyota");
    carRec.addEdge(0,"Camry");
    carRec.addEdge(0,"Corolla");
    carRec.addEdge(0,"RAV4");
    carRec.addEdge(0,"HighLander");
    carRec.addEdge(0,"Grand HighLander");

    //Toyota connected to other brands
    carRec.addEdge(0,"Honda");
    carRec.addEdge(0,"Lexus");

    //Honda Vertex
    carRec.addEdge(1,"Honda");
    carRec.addEdge(1,"Civic");
    carRec.addEdge(1,"Accord");
    carRec.addEdge(1,"Pilot");
    carRec.addEdge(1,"HRV");
    carRec.addEdge(1,"CRV");

    //Honda Conncted to other brands
    carRec.addEdge(1,"Toyota");
    carRec.addEdge(1,"Lexus");

    //Lexus Vertex
    carRec.addEdge(2,"Lexus");
    carRec.addEdge(2,"ES350");
    carRec.addEdge(2,"IS350");
    carRec.addEdge(2,"LS500");
    carRec.addEdge(2,"TX350");
    carRec.addEdge(2,"GX550");
    
    //Lexus connected to other brands
    carRec.addEdge(2,"Toyota");
    carRec.addEdge(2,"Honda");

    do{
        cout<<"Enter the number for each operation: \n1. Add Vehicle to inventory\n2. Delete Vehicle from inventory\n3. Search for car\n4. Display Information\n5. Update Inventory\n6. Add cars to display for sale\n7. Displays Operation History\n8. Clears Operation History\n9. Add vehicle to detail to be displayed\n10. Service Queue menu\n11. Recommennded Vehicles to buy!\n12. Search for recommended vehicle brands and makes\n13. Ratings of reliability for each brand\n14. Exit "<<endl;
        cin>>num;
        switch(num){
            case 1:{ 
                //Adds cars and sale date to inventory
                
                cout<<"Enter the Brand and Model of vehicle(Use an underscore for space): ";
                cin>>brandModel;
                cout<<"Enter the date of car bought by dealer: ";
                cin>>dateSold;
                Car newCar(brandModel,dateSold);
                string histlog = brandModel + " Added to inventory";
                car.push_back(newCar);
                ll.push_back(dateSold);
                history.push(histlog);
                break;
            }   
            case 2:{
                //deletes the cars in inventory
                cout<<"Enter the brand and model of vehicle you want to delete(Use an underscore for space): ";
                cin>>name;
                string delhist = name + " Deleted from inventory";
                //size of the array
                int size = 5;
                 if(car.empty()){
                        cout<<"Inventory is empty"<<endl;
                        break;
                }
                int count = -1;
                    //For each used for deleting in the vector and linked list at the same time
                for(int i = 0;i<car.size();i++){
                    if(car[i].getBrandModel()==name){
                        count = i;
                        break;
                    }
                }
                if(count==-1){
                    cout<<"Car Not found"<<endl;
                    break;
                }
                //deletes the car from vector
                car.erase(car.begin()+count);
                //deletes date from Linked list
                ll.deleteAt(count+1);
                    //for loop for deleting an element in the arr
                for(int i = 0;i<displayCount;i++){
                    if(name == arr[i]){
                        for(int j = i;j<displayCount-1;j++){
                            arr[j] = arr[j+1];
                        }
                        displayCount--;
                        arr[displayCount]="";

                        break;
                    }
                }
                    
                history.push(delhist);
                break;
            }
            case 3:{
                //searches for the cars in inventory
              
                int flag = 1;
                if(car.empty()){
                    cout<<"List is empty"<<endl;
                    break;
                }
                cout<<"Enter the brand and model of vehicle if its available: ";
                cin>>findCar;
                string searchcar = "Searched for "+ findCar;
                //for each loop to find the idx and see if car is in the inventory
                for(int i = 0;i<car.size();i++){
                    if(findCar == car[i].getBrandModel()){
                        cout<<"Car is available"<<endl;
                        flag = 0;
                        break;
                    }
                   
                
                    
                }
                if(flag){
                    cout<<"Car isn't Available"<<endl;
                }
                history.push(searchcar);
                break;
            }
            case 4:{
            //print values from linked list, vector and array
                cout<<"Car Inventory:\n";
                for(int i =0;i<car.size();i++){
                    cout<<i+1<<". ";
                    car[i].print();
                }
                ll.printll();
                cout<<"Cars on Display: "<<endl;
                for(int i =0;i<5;i++){
                    cout<<arr[i]<<endl;
                }
                cout<<"Cars In Queue for Detail: "<<endl;
                cleancar.display();
                cout<<"Service Line: "<<endl;
                service.display();
                break;
            }
            case 5:{
                //Update Value
                
                string oldname;
                cout<<"Enter the Brand and Model of vehicle that you want to update(Use an underscore for space): ";
                cin>>oldname;
                string newname;
                cout<<"Enter the Brand and Model of vehicle to replace the old vehicle(Use an underscore for space): ";
                cin>>newname;
                string newdate;
                cout<<"Enter date of the updated car bought by dealer: ";
                cin>>newdate;
                string updateHistory = oldname + " is updated with " + newname;
                //loops through to see if the old name equals to whats in the vector 
                //and changes the value to the newname and new date is sent to linked list 
                //to change the date it was sold
                int flag = 0;
                for(int i =0;i<car.size();i++){
                    if(car[i].getBrandModel() == oldname){
                        car[i].setBrandModel(newname);
                        car[i].setDateSold(newdate);
                        ll.update(newdate, i+1);
                        flag = 1;
                        break;
                    }
                
                }
                //updates the array for the cars on display by removing the old one that doesnt exist
                for(int i = 0;i<displayCount;i++){
                    if(oldname == arr[i]){
                        for(int j = i;j<displayCount-1;j++){
                            arr[j] = arr[j+1];
                        }
                        displayCount--;
                        arr[displayCount]="";
                        break;
                    }
                }
                //Flag to check if the car isn't in the vector
                if(!flag){
                    cout<<"Car isn't found";
                }
                history.push(updateHistory); 
                break;
            } 
            case 6:{
                string car_to_display;
                int flag = 0;
                int count = 0;
                cout<<"Enter the available car you want to be displayed(Only 5 cars can be displayed): ";
                cin>>car_to_display;
                string history_display = car_to_display + " is finished from detail and added to display";
                
                //Adds cars to be displayed in an array
                if(car_to_display == cleancar.front()){
                    for(int i =0;i<car.size();i++){
                        if(car_to_display == car[i].getBrandModel()){
                            flag = 1;
                            if(displayCount<5){
                                arr[displayCount] = car_to_display;
                                displayCount++;
                                cout<<"Car added to display"<<endl;
                                cleancar.dequeue();
                               
                            }
                            else{
                                cout<<"Display is Full"<<endl;
                    

                            }
                        }
                    }
                }
                else{
                    cout<<"Vehicle is not ready for display"<<endl;
                    break;
                }
                
                //checks flag to see if the car exists
                if(!flag){
                    cout<<"Car is not in inventory"<<endl;
                }
                history.push(history_display);
                break;
                
               

            }
            case 8:{
                //Deletes the history of operations you have
                cout<<"History has been cleared"<<endl;
                history.clear();
                break;
            }
            case 7:{
                //prints the history of the operations done
                cout<<"Operations History:\n";
                history.display();
                break;
            }
            case 9:{
                //adds cars to be in a queue for detail
                string queuecar;
            
                cout<<"Enter the cars that you have in inventory to be placed in queue: ";
                cin>>queuecar;
                string histdetail = queuecar + " added to detail queue";
                for(int i = 0;i<car.size();i++){
                    if(queuecar == car[i].getBrandModel()){
                        cleancar.enqueue(queuecar);
                        history.push(histdetail);
                        break;
                    }
                }
                break;
            }
            case 10:{
                char choice;
                string car_be_serviced;
                do{
                
                    cout<<"Service Menu: \nA. Adds vehicle to service queue\nP. Prints the Service Queue\nD. Removes first vehicle from service queue\nQ. Quit Service Menu\n";
                    cin>>choice;
                    switch(choice){
                    //adds cars to be put into a circular queue for service
                        case 'A':{
                            cout<<"Enter the Customer vehicle that is being serviced(IF Spaced use underscore): ";
                            cin>>car_be_serviced;
                            service.enqueue(car_be_serviced);
                            break;
                        }
                        //prints the circular queue
                        case 'P':{
                            cout<<"Cars in Service Queue:\n";
                            service.display();
                            break;
                        }
                        //removes the first car in queue
                        case 'D':{
                            if(!service.isempty()){
                                cout<<"First Vehicle removed from Service line"<<endl;
                            }
                            service.dequeue();
                            
                            break;
                        
                        }
                    }
                }while(choice!='Q');

                break;
            }
            case 11:{
                //prints the recommendation graph
                carRec.displayGraph();
                break;
            }
            case 12:{
                char choice;
                //menu for searching for car brands and makes with breadth first and depth first search
                do{
                    cout<<"V. To search for a Brand we recommend\nE. To search for a make we recommend\nQ. Quits Menu\n";
                    cin>>choice;
                    switch(choice){
                        case 'V':{
                            //finds the brand
                            string brand_name;
                            cout<<"Enter the Brand you are searching for in our recommendation: ";
                            cin>>brand_name;
                            bool found = carRec.searchVertex(0,brand_name);

                            if(found==false){
                                cout<<"Brand is not recommended"<<endl;
                            }
                            else{
                                cout<<"Vehicle brand is recommended"<<endl;
                            }
                            break;
                        }
                        case 'E':{
                            //finds the make
                            string make_name;
                            cout<<"Enter the Make you are searching for in our recommendation: ";
                            cin>>make_name;
                            bool foundedge = carRec.searchEdge(0,make_name);
                            if(foundedge==false){
                                cout<<"Make is not recommended"<<endl;
                            }
                            else{
                                cout<<"Vehicle Make is recommended"<<endl;
                            }
                            break;

                        }
                    }
                }while(choice!='Q');
                break;
            }
            case 13:{
                //sees the ratings of each car brand by reliability
                vector<int> mst = carRec.primMST(0);
                carRec.printMST(mst);
                break;
            }

        }
    }while(num!=14);
    
    return 0;

}