""" Content based recommendation system using Neural Networks """
import numpy as np
import numpy.ma as ma
import pandas as pd
import tensorflow as tf
from tensorflow import keras
from sklearn.preprocessing import StandardScaler, MinMaxScaler
from sklearn.model_selection import train_test_split
import tabulate
from recsysNN_utils import *
pd.set_option("display.precision", 1)



####################### 2 - Movie ratings dataset #######################
"""
The dataset has been reduced in size to focus on movies from the years since 2000 and popular genres. 
The reduced dataset has  n_u=397 users,  n_m=847 movies and 25521 ratings on a scale of 0.5 to 5 in 0.5 step increments.
This dataset contains little information about users other than their ratings. 
This dataset is used to create training vectors for the neural networks described below.
"""
top10_df = pd.read_csv("./C3_W2/data2/content_top10_df.csv")
bygenre_df = pd.read_csv("./C3_W2/data2/content_bygenre_df.csv")
print(top10_df)
print("\n")
print(bygenre_df)


####################### 3 - Content-based filtering with a neural network #######################

############ 3.1 Training Data ############

"""
The movie content provided to the network is a combination of the original data and some 'engineered features'. 
Recall the feature engineering discussion and lab from Course 1, Week 2, lab 4. The original features are the year the movie was 
released and the movie's genre's presented as a one-hot vector. There are 14 genres. The engineered feature is an average 
rating derived from the user ratings.

The user content is composed of engineered features. A per genre average rating is computed per user. 
Additionally, a user id, rating count and rating average are available but not included in the training or prediction content. 
They are carried with the data set because they are useful in interpreting data.
"""
"""
The training set consists of all the ratings made by the users in the data set. 
Some ratings are 'repeated' to boost the number of training examples of underrepresented genre. 
The training set is split into two arrays with the same number of entries, a user array and a movie/item array.
"""

# Load Data, set configuration variables
item_train, user_train, y_train, item_features, user_features, item_vecs, movie_dict, user_to_genre = load_data()

print("\nitem/movie features: ", item_features)
print("\nuser features: ", user_features)
num_item_features = item_train.shape[1] - 1  # remove movie id at train time
num_user_features = user_train.shape[1] - 3  # remove userid, rating count and ave rating during training
uvs = 3  # user genre vector start
ivs = 3  # item genre vector start
u_s = 3  # start of columns to use in training, user
i_s = 1  # start of columns to use in training, items
print(f"Number of training vectors: {len(item_train)}")
print(f"Number of user vectors: {len(user_train)}")
print("\nitem_train shape: ", item_train.shape)
print("user_train shape: ", user_train.shape)
print("y.shape: ", y_train.shape)
"""".DS_Store"""
"""Let's look at the first few entries in the user training array."""
"""
"""
pprint_train(user_train, user_features, uvs,  u_s, maxcount=5)
"""Let's look at the first few entries in the item training array."""
pprint_train(item_train, item_features, ivs, i_s, maxcount=5, user=False)
"""Let's look at the first few entries in the y_train array."""
print(f"y_train[:5]: {y_train[:5]}")

"""
A single training example consists of a row from both the user and item arrays and a rating from y_train. Where,
"""


print("\n\n")

############ 3.2 Preparing the training data ############

"""
Recall in Course 1, Week 2, you explored feature scaling as a means of improving convergence. 
We'll scale the input features using the scikit learn StandardScaler. This was used in Course 1, Week 2, Lab 5. 
Below, the inverse_transform is also shown to produce the original inputs. We'll scale the target ratings using a Min Max Scaler 
which scales the target to be between -1 and 1.
"""
# scale training data
"""Standard Scaling transforms the data such that the mean becomes 0 and the standard deviation becomes 1."""
item_train_unscaled = item_train
user_train_unscaled = user_train
y_train_unscaled    = y_train

scalerItem = StandardScaler()
scalerItem.fit(item_train)
item_train = scalerItem.transform(item_train)

scalerUser = StandardScaler()
scalerUser.fit(user_train)
user_train = scalerUser.transform(user_train)

scalerTarget = MinMaxScaler((-1, 1))
scalerTarget.fit(y_train.reshape(-1, 1))
y_train = scalerTarget.transform(y_train.reshape(-1, 1))
#ynorm_test = scalerTarget.transform(y_test.reshape(-1, 1))

print(np.allclose(item_train_unscaled, scalerItem.inverse_transform(item_train)))
print(np.allclose(user_train_unscaled, scalerUser.inverse_transform(user_train)))


"""
To allow us to evaluate the results, we will split the data into training and test sets as was discussed in Course 2, Week 3. 
Here we will use sklean train_test_split to split and shuffle the data. Note that setting the initial random state 
to the same value ensures item, user, and y are shuffled identically.
"""
item_train, item_test = train_test_split(item_train, train_size=0.80, shuffle=True, random_state=1)
user_train, user_test = train_test_split(user_train, train_size=0.80, shuffle=True, random_state=1)
y_train, y_test       = train_test_split(y_train,    train_size=0.80, shuffle=True, random_state=1)
print(f"\nmovie/item training data shape: {item_train.shape}")
print(f"movie/item test data shape: {item_test.shape}")

"""The scaled, shuffled data now has a mean of zero."""
pprint_train(user_train, user_features, uvs, u_s, maxcount=5)







####################### 4 - Neural Network for content-based filtering #######################
"""
Now, let's construct a neural network as described in the figure above. It will have two networks that are combined by a dot product. 
You will construct the two networks. In this example, they will be identical. Note that these networks do not need to be the same. 
If the user content was substantially larger than the movie content, you might elect to increase the complexity of the user network 
relative to the movie network. In this case, the content is similar, so the networks are the same.
"""

######### 4.1 - Constructing the neural network model #########


"""
Use a Keras sequential model
    The first layer is a dense layer with 256 units and a relu activation.
    The second layer is a dense layer with 128 units and a relu activation.
    The third layer is a dense layer with num_outputs units and a linear or no activation.
The remainder of the network will be provided. The provided code does not use the Keras sequential model but instead 
uses the Keras functional api. This format allows for more flexibility in how components are interconnected.
"""
#Exercise 1
# GRADED_CELL
# UNQ_C1

num_outputs = 32
tf.random.set_seed(1)
user_NN = tf.keras.models.Sequential([
    ### START CODE HERE ###     
    tf.keras.layers.Dense(256,activation='relu'),
    tf.keras.layers.Dense(128,activation='relu'),
    tf.keras.layers.Dense(num_outputs)
    ### END CODE HERE ###  
])

item_NN = tf.keras.models.Sequential([
    ### START CODE HERE ###     
    tf.keras.layers.Dense(256,activation='relu'),
    tf.keras.layers.Dense(128,activation='relu'),
    tf.keras.layers.Dense(num_outputs)
    ### END CODE HERE ###  
])

# create the user input and point to the base network
input_user = tf.keras.layers.Input(shape=(num_user_features,))
vu = user_NN(input_user)
#vu = tf.linalg.l2_normalize(vu, axis=1) #produces error
vu = tf.keras.layers.Lambda(lambda x: tf.linalg.l2_normalize(x, axis=1))(vu)  # Use Lambda to apply l2_normalize

# create the item input and point to the base network
input_item = tf.keras.layers.Input(shape=(num_item_features,))
vm = item_NN(input_item)
#vm = tf.linalg.l2_normalize(vm, axis=1) #produces error
vm = tf.keras.layers.Lambda(lambda x: tf.linalg.l2_normalize(x, axis=1))(vm)  # Use Lambda to apply l2_normalize


# compute the dot product of the two vectors vu and vm
output = tf.keras.layers.Dot(axes=1)([vu, vm])

# specify the inputs and output of the model
model = tf.keras.Model([input_user, input_item], output)

model.summary()


# # Public tests
# from public_tests2 import *
# test_tower(user_NN)
# test_tower(item_NN)





######### 4.2 - Training the model #########

# We will use a mean squared error loss and an Adam optimizer.
tf.random.set_seed(1)
cost_fn = tf.keras.losses.MeanSquaredError()
opt = keras.optimizers.Adam(learning_rate=0.01)
model.compile(optimizer=opt,loss=cost_fn)
tf.random.set_seed(1)
model.fit([user_train[:, u_s:], item_train[:, i_s:]], y_train, epochs=30)

# Evaluate the model to determine loss on the test data.
model.evaluate([user_test[:, u_s:], item_test[:, i_s:]], y_test)






####################### 5 - Predictions #######################
"""Below, you'll use your model to make predictions in a number of circumstances."""

############ 5.1 - Predictions for a new user ############
"""
First, we'll create a new user and have the model suggest movies for that user. After you have tried this on 
the example user content, feel free to change the user content to match your own preferences and see what the model suggests. 
Note that ratings are between 0.5 and 5.0, inclusive, in half-step increments.
"""
new_user_id = 5000
new_rating_ave = 0.0
new_action = 0.0
new_adventure = 5.0
new_animation = 0.0
new_childrens = 0.0
new_comedy = 0.0
new_crime = 0.0
new_documentary = 0.0
new_drama = 0.0
new_fantasy = 5.0
new_horror = 0.0
new_mystery = 0.0
new_romance = 0.0
new_scifi = 0.0
new_thriller = 0.0
new_rating_count = 3

user_vec = np.array([[new_user_id, new_rating_count, new_rating_ave,
                      new_action, new_adventure, new_animation, new_childrens,
                      new_comedy, new_crime, new_documentary,
                      new_drama, new_fantasy, new_horror, new_mystery,
                      new_romance, new_scifi, new_thriller]])
            
"""
The new user enjoys movies from the adventure, fantasy genres. Let's find the top-rated movies for the new user.

Below, we'll use a set of movie/item vectors, item_vecs that have a vector for each movie in the training/test set. 
This is matched with the new user vector above and the scaled vectors are used to predict ratings for all the movies.
"""
# generate and replicate the user vector to match the number movies in the data set.
user_vecs = gen_user_vecs(user_vec,len(item_vecs))

# scale our user and item vectors
scaled_user_vecs = scalerUser.transform(user_vecs)
scaled_item_vecs = scalerItem.transform(item_vecs)

# make a prediction
y_p = model.predict([scaled_user_vecs[:, u_s:], scaled_item_vecs[:, i_s:]])

# unscale y prediction 
y_p_unscaled = scalerTarget.inverse_transform(y_p)

# sort the results, highest prediction first
sorted_index = np.argsort(-y_p_unscaled,axis=0).reshape(-1).tolist()  #negate to get largest rating first
sorted_yp_unscaled   = y_p_unscaled[sorted_index]
sorted_items = item_vecs[sorted_index]  #using unscaled vectors for display

print_pred_movies(sorted_yp_unscaled, sorted_items, movie_dict, maxcount = 10)





############ 5.2 - Predictions for an existing user ############
"""
Let's look at the predictions for "user 2", one of the users in the data set. We can compare the predicted ratings with the model's ratings.
"""
uid = 2 
# form a set of user vectors. This is the same vector, transformed and repeated.
user_vecs, y_vecs = get_user_vecs(uid, user_train_unscaled, item_vecs, user_to_genre)

# print("\n", user_vecs,"\n",user_vecs.shape)
# print("\n", y_vecs,"\n",y_vecs.shape)

# scale our user and item vectors
scaled_user_vecs = scalerUser.transform(user_vecs)
scaled_item_vecs = scalerItem.transform(item_vecs)

# make a prediction
y_p = model.predict([scaled_user_vecs[:, u_s:], scaled_item_vecs[:, i_s:]])

# unscale y prediction 
y_p_unscaled = scalerTarget.inverse_transform(y_p)

# sort the results, highest prediction first
sorted_index = np.argsort(-y_p_unscaled,axis=0).reshape(-1).tolist()  #negate to get largest rating first
sorted_y_p_unscaled   = y_p_unscaled[sorted_index]
sorted_items = item_vecs[sorted_index]  #using unscaled vectors for display
sorted_user  = user_vecs[sorted_index]
sorted_y     = y_vecs[sorted_index]

#print sorted predictions for movies rated by the user
print_existing_user(sorted_y_p_unscaled, sorted_y.reshape(-1,1), sorted_user, sorted_items, ivs, uvs, movie_dict, maxcount = 50)

"""
The model prediction is generally within 1 of the actual rating though it is not a very accurate predictor of how 
a user rates specific movies. This is especially true if the user rating is significantly different than the user's 
genre average. You can vary the user id above to try different users. Not all user id's were used in the training set.
"""





############ 5.3 - Finding Similar Items ############
"""
The neural network above produces two feature vectors, a user feature vector  vu, and a movie feature vector,  vm.
 These are 32 entry vectors whose values are difficult to interpret. However, similar items will have similar vectors. 
 This information can be used to make recommendations. For example, if a user has rated "Toy Story 3" highly, one could 
 recommend similar movies by selecting movies with similar movie feature vectors.

A similarity measure is the squared distance between the two vectors  v^(k)_m and  v^(i)_m
"""

# GRADED_FUNCTION: sq_dist
# UNQ_C2
def sq_dist(a,b):
    """
    Returns the squared distance between two vectors
    Args:
      a (ndarray (n,)): vector with n features
      b (ndarray (n,)): vector with n features
    Returns:
      d (float) : distance
    """
    ### START CODE HERE ###
    d = 0
    n = len(a)
    for i in range(n):
        d += (a[i]-b[i])**2
    ### END CODE HERE ###     
    return d

a1 = np.array([1.0, 2.0, 3.0]); b1 = np.array([1.0, 2.0, 3.0])
a2 = np.array([1.1, 2.1, 3.1]); b2 = np.array([1.0, 2.0, 3.0])
a3 = np.array([0, 1, 0]);       b3 = np.array([1, 0, 0])
print(f"squared distance between a1 and b1: {sq_dist(a1, b1):0.3f}")
print(f"squared distance between a2 and b2: {sq_dist(a2, b2):0.3f}")
print(f"squared distance between a3 and b3: {sq_dist(a3, b3):0.3f}")

# Public tests
from public_tests2 import *
test_sq_dist(sq_dist)




"""
A matrix of distances between movies can be computed once when the model is trained and then reused for new recommendations 
without retraining. The first step, once a model is trained, is to obtain the movie feature vector,  𝑣𝑚, for each of the movies. 

To do this, we will use the trained item_NN and build a small model to allow us to run the movie vectors through it to 
generate  𝑣𝑚.
"""

input_item_m = tf.keras.layers.Input(shape=(num_item_features,))    # input layer
vm_m = item_NN(input_item_m)                                       # use the trained item_NN
#vm_m = tf.linalg.l2_normalize(vm_m, axis=1)    #produces error    # incorporate normalization as was done in the original model 
vm_m = tf.keras.layers.Lambda(lambda x: tf.linalg.l2_normalize(x, axis=1))(vm_m)  # Use Lambda to apply l2_normalize
model_m = tf.keras.Model(input_item_m, vm_m)                                
model_m.summary()


"""
Once you have a movie model, you can create a (set of movie feature vectors) or (vm) by using the model to predict 
using a (set of item/movie vectors) or (xm) as input. item_vecs is a set of all of the 'distinct' movie vectors. 
It must be scaled to use with the trained model. The result of the prediction is a 32 entry feature vector for each movie.
"""

# scale our item vectors
scaled_item_vecs = scalerItem.transform(item_vecs)
vm_scaled = model_m.predict(scaled_item_vecs[:,i_s:])
print(f"\nsize of all predicted movie feature vectors: {vm_scaled.shape}\n")




#Let's now compute a matrix of the squared distance between each movie feature vector and all other movie feature vectors:
"""
We can then find the closest movie by 'finding the minimum along each row'. We will make use of numpy masked arrays 
to avoid selecting the same movie. The masked values along the diagonal won't be included in the computation.
"""
count = 224  # number of movies to display
dim = len(vm_scaled)
dist = np.zeros((dim,dim))

for i in range(dim):
    for j in range(dim):
        dist[i,j] = sq_dist(vm_scaled[i, :], vm_scaled[j, :])
        
m_dist = ma.masked_array(dist, mask=np.identity(dist.shape[0]))  # mask the diagonal
print(f"\nm_dist.shape={m_dist.shape}\n")
print(m_dist)

disp = [["movie1", "genres", "movie2", "genres"]]
for i in range(count):
    min_idx = np.argmin(m_dist[i])
    movie1_id = int(item_vecs[i,0])
    movie2_id = int(item_vecs[min_idx,0])
    disp.append( [movie_dict[movie1_id]['title'], movie_dict[movie1_id]['genres'],
                  movie_dict[movie2_id]['title'], movie_dict[movie1_id]['genres']]
               )
table = tabulate.tabulate(disp, tablefmt='html', headers="firstrow")

print(table)

"""The results show the model will generally suggest a movie with similar genre's."""

"""
This structure is the basis of many commercial recommender systems. 
The user content can be greatly expanded to incorporate more information about the user if it is available. 
Items are not limited to movies. This can be used to recommend any item, books, cars or items that are similar to an item in your 'shopping cart'.
"""