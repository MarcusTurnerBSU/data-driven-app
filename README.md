# CodeLab II (CCO5000-20)
# Data Driven Application Option 1 - Assignment 2

### Task

For this assignment you are tasked with developing an application that interrogates tweets. The application should be designed to use functions and pass arguments between these as appropriate. Where possible the application should also implement object oriented programming techniques.

To complete the assignment you should utilise the ‘sampleTweets’ file that contains a set of tweets from the top 20 users on Twitter. Your program must provide a minimum of 10 sample queries that should include:

* Count the total number of tweets in the data set
* Count the number of tweets that include “money”.
* Count the number of tweets that include “politics”.
* Print to the screen any tweets that include “Paris”
* Print to the screen any tweets that include “DreamWorks”
* Print to the screen any tweets that include “Uber”.
* Plus a minimum of 4 queries of your own (you should aim to add variety to these queries).

The final application should be delivered via a functioning interactive GUI built using openFrameworks. This GUI should allow the user to use the sample queries via mouse and/or keyboard input.

*Note the file of tweets is located in the ```bin/data``` folder of your project. So that the code files can properly read from this you need to ensure you use the correct file path when loading it in. To do this you can make use of the openFrameworks method ```ofToDataPath``` to get the correct file path. The below code snippet shows how you can open the file using an ```fstream``` object*

```C++
inFile.open(ofToDataPath("sampleTweets.csv"));
```

### Guides

A series of guides are provided in the guides folder. These include guides on cloning this repository to your local machine correctly setting up the initial project.

### Deliverables

The deliverables for the Data Driven Application are as follows:

#### The Application

The C++ code and any supplementary files required to run your data driven console application and openFrameworks GUI. These files should be committed to this GitHub repository for this assignment.

*If you are unsure - ask!*

#### The Development Document

Your data driven application must be accompanied by a Development Document of a minimum of 1000 words (there is no maximum word count). This development document should consist of the following elements:

* Abstract
* Project Plan
* Evidence of design
* Technical Description
* Testing
* Critical Reflection
* Appendix

See the brief for full details of the requirements for each option.

The development document should be submitted via Turnitin. The development document should include a link to your Github repository.

*Incorrect submission will result in marks being deducted.*


### Deadline

**Friday 5 February, 2021 - 11:59**

*Only code submitted ahead of this deadline will be marked*
