# Setting up the Assignment - Xcode

[Click here to view a video guide on setting up the assignment](https://www.loom.com/share/143119606aeb41659d4f6f16b1262884)

## Step 1

So far we have successfully created your repository on GitHub, but we need to download this to your machine so you can write your code and then send this back to GitHub. For this we will use GitHub desktop.

Open GitHub desktop and clone the repository. If you have no existing repositories you can do this by clicking the ```Clone a Repository``` button on the opening screen. If you already have some repositories downloaded you can add another on by selecting ```File --> Clone Repository``` from the menu bar.

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/get-started-screen.png">
</p>

&nbsp;
&nbsp;

## Step 2

You will be presented with Clone a Repository screen similar to the one below. You should look for the repository you wish to clone from those listed. This will be named something like: CodeLab-II-20-21/data-driven-app-option-1-yourgithubusername

<p align="center">
  <img width="50%" src="https://jakehobbs.co.uk/markdown_images/clone-opt1.png">
</p>

&nbsp;
&nbsp;

## Step 3

Click ```Choose...``` next to local path and browse to the ```myApps``` folder of your openFrameworks installation. If you do not have a ```myApps``` folder, create one. Once you have found this folder Click ```Open```

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/my-apps-opt1.png">
</p>

Now click ```Clone``` and this will clone the repository.

&nbsp;
&nbsp;

## Step 4

You should now have a copy of the repository from Github on your local machine. The image below shows the cloned repository after downloading to my mac.

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/cloned-opt1.png">
</p>

&nbsp;
&nbsp;

## Step 5

Now we need to create the openFrameworks project to begin coding. To do so we will use the project generator and import the template files provided in the repository.

Open the project generator and click ```Import```

<p align="center">
  <img width="50%" src="https://jakehobbs.co.uk/markdown_images/project-generator-opt1.png">
</p>

*Note: if this is the first time you have opened the project generator you may get a warning that says the openFrameworks path is wrong. To fix this issue we need to set the openFrameworks path to the root folder of your openFrameworks installation. This is the folder that contains all the other folders such as addons, libs, apps, projectGenerator etc. Follow the steps below if you get this warning*

* Click the 🔍 icon on the openFrameworks path input box.
* Browse to the root openFrameworks folder
* Click open

&nbsp;
&nbsp;

## Step 6

Navigate to your repository folder located in the ```myApps``` folder and click ```Open```.

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/opt1-location.png">
</p>

&nbsp;
&nbsp;

## Step 7

Now click ```Update```. This will generate the required project files.

<p align="center">
  <img width="50%" src="https://jakehobbs.co.uk/markdown_images/opt1-update.png">
</p>

&nbsp;
&nbsp;

## Step 8

After a few moments (please wait after clicking update and do not click update again - this will duplicate the process) the below message will appear. Click ```Open in IDE``` and your project will open in Xcode.

<p align="center">
  <img width="50%" src="https://jakehobbs.co.uk/markdown_images/opt1-success.png">
</p>

&nbsp;
&nbsp;

## Step 9

Your project is now ready to begin coding. To check it builds the ```Build and Run``` icon :arrow_forward:

The first build may take a while, subsequent builds will be much quicker. A blank grey GUI window should appear if the starting project builds successfully

*Note the file of tweets is located in the ```bin/data``` folder of your project. So that the code files can properly read from this you need to ensure you use the correct file path when loading it in. To do this you can make use of the openFrameworks method ```ofToDataPath``` to get the correct file path. The below code snippet shows how you can open the file using an ```fstream``` object*

```C++
inFile.open(ofToDataPath("sampleTweets.csv"));
```

## Step 10

To ensure you are able to read the sampleTweets file you need to give Xcode permission to read file. To do so go select ```Product → Scheme → Edit scheme``` from the toolbar menu

<p align="center">
  <img width="50%" src="https://jakehobbs.co.uk/markdown_images/product-scheme.png">
</p>

In the window that appears ensure the ```Working Directory``` checkbox is selected.

<p align="center">
  <img width="60%" src="https://jakehobbs.co.uk/markdown_images/working-dir.png">
</p>

Now click the folder icon in the working directory path and navigate to the ```bin/data``` folder of your project where you will find the ```sampleTweets.csv``` file located.

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/file-path.png">
</p>

&nbsp;
&nbsp;

## Step 11

You are now ready to begin developing your Data Driven App. Github Desktop will keep track of your changes. You should regular make commits to ensure you can fall back to previous versions if things go wrong. You should also push your commits back up to your Github repository often, this will make sure you have a backup of your work. To make commits write a descriptive message for the changes you have made and click ```commit to master```.

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/commit-opt1.png">
</p>

It would also be a good idea to make use of branches as you add new features. This will allow you to test these new features in the knowledge that you can switch back to your “master” branch if the new feature doesn’t work out.

&nbsp;
&nbsp;

## Step 12

When making commits you should also push your your work to GitHub this will make sure you have a backup of your work. Most importantly when you are happy with your final solution don't forget to make sure you make one final commit and push to your final code before the deadline. To push code to GitHub click ```Push Origin``` after making a commit.

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/push-origin.png">
</p>

&nbsp;
&nbsp;

## Step 13

To check your code has submitted correctly go to your repository on GitHub, the URL for this will be: ```github.com/codelab-ii-20-21/data-driven-app-option-2-YOURGITHUBUSERNAME```.

You can also easily get to your repository on GitHub by clicking the ```View on GitHub``` button in GitHub Desktop.

<p align="center">
  <img width="70%" src="https://jakehobbs.co.uk/markdown_images/view-on-github.png">
</p>
