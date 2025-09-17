class FoodRatings {
public:
    map<string, int> food_rating;
    map<string, set<pair<int, string>>> cuisines_rating_foods;
    map<string, string> food_cuisine;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();

        for(int i=0; i<n; i++){
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];

            cuisines_rating_foods[cuisine].insert({-rating, food});
            food_cuisine[food] = cuisine;
            food_rating[food] = rating;
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = food_cuisine[food];
        int oldRating = food_rating[food];

        food_rating[food] = newRating;
        cuisines_rating_foods[cuisine].erase({-oldRating, food});
        cuisines_rating_foods[cuisine].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        return begin(cuisines_rating_foods[cuisine])->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */