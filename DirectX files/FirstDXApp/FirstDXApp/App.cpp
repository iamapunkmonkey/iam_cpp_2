#include "pch.h"

// Use some common namespaces to simplify the code

using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Core; //IFrameworkView, CoreApplicationView, TypedEventHandler, IFrameWorkViewSource, CoreApplication
using namespace Windows::ApplicationModel::Activation; // TypedEventHandler, IActivatedEventArgs
using namespace Windows::UI::Core; // CoreWindow
using namespace Windows::UI::Popups; //nothing yet
using namespace Windows::System; //nothing yet
using namespace Windows::Foundation; //CoreApplicationView, TypedEventHandler
using namespace Windows::Graphics::Display; //nothing yet
using namespace Platform; // String, App

bool WindowClosed;

// the class definition for the core "framework" of our app
ref class App sealed : public IFrameworkView
{
public:
	// some functions called by Windows
	virtual void Initialize(CoreApplicationView^ AppView)
	{
		// set the OnActivated function to handle to Activated "event"
		AppView->Activated += ref new TypedEventHandler
			<CoreApplicationView^, IActivatedEventArgs^>(this, &App::OnActivated);

		CoreApplication::Suspending +=
			ref new EventHandler<SuspendingEventArgs^>(this, &App::Suspending);
		CoreApplication::Resuming +=
			ref new EventHandler<Object^>(this, &App::Resuming);

		WindowClosed = false; //init to false
	}

	//we wrote a function to handle the event, but now we must inform windows that we wrote it.
	//Something to handle the "ProcessEvents" class we called in the Run() method
	virtual void SetWindow(CoreWindow^ Window) {
		Window->KeyDown += ref new TypedEventHandler
			<CoreWindow^, KeyEventArgs^>(this, &App::KeyDown);

		Window->Closed += ref new TypedEventHandler
			<CoreWindow^, CoreWindowEventArgs^>(this, &App::Closed);
	}
	virtual void Load(String^ EntryPoint) {}
	virtual void Run() {
		CoreWindow^ Window = CoreWindow::GetForCurrentThread();

		Window->Dispatcher->ProcessEvents(CoreProcessEventsOption::ProcessUntilQuit); //**ProcessUntilQuit does not have much affect on games/apps, now we learn about other functions that are used when we need 3D rendered objects
		//see below while loop for example
		
		//CoreProcessEventsOption is a state machine, it has 4 different enumerated states
		//ProcessOneIfPresent, ProcessAllIfPresent, ProcessOneAndAllPending, ProcessUntilQuit 
		//each do different things so if you need to know which one to use
		//google that shit to figure it out. 
		//Cheat Sheet:

		//****ProcessOneIfPresent : Dispatch the next event waiting on the queue (if any).
		//***ProcessAllIfPresent : Dispatch the next event waiting on the queue(if any) and 
		//repeat until all waiting events are handled, then return.

		//****ProcessOneAndAllPending : Dispatch all waiting events.If there are none waiting, 
		//wait until another one arrives.

		//****ProcessUntilQuit : Dispatch all events, and repeat.Do not return until Windows shuts 
		//the program down.

		// repeat until window closes
		while (!WindowClosed)
		{
			Window->Dispatcher->ProcessEvents(CoreProcessEventsOption::ProcessAllIfPresent); //**as opposed to ProcessUntilQuit, ProcessAllIfPresent

			// Run game code here
			// ...
			// ...
		}
	}
	virtual void Uninitialize() {}

	// an "event" that is called when the application window is ready to be activated
	void OnActivated(CoreApplicationView^ CoreAppView, IActivatedEventArgs^ Args) 
		// The first parameter, CoreApplicationView^, is the same parameter found in the Initialize() function.
		//The second parameter, IActivatedEventArgs^, is a parameter that will give us useful information about the circumstances 
		//under which the function was called(remember, we aren't calling it).

		//NOTE: we just ignore the params anyways.
	{

		//CoreWindow::GetForCurrentThread() is a simple function that returns a hat pointer to the window. 
		//The window itself is already "created", but just needs to be activated.
		//Once we have obtained the pointer, we call Activate() on that pointer, and the window appears
		CoreWindow^ Window = CoreWindow::GetForCurrentThread(); //^ = hat pointer, refers to a managed block of memory
		//while a unmanaged pointer (*) refers to a pointer that points to a function.
		//there's another kind of pointer as well an unmanaged function pointer, should look that up
		Window->Activate(); //pushing what was just created
	}

	//This is where we call events (mouse click, or mouse position, key press.. etc)
	//CoreWindow is always the first parameter, although we might not really use it.
	//PointerEventArgs tells us about the pointer-press (where on the screen it was made, what type of press it was..etc, exactly when it was made, and more.
	void PointerPressed(CoreWindow^ Window, PointerEventArgs^ Args)
	{
		MessageDialog Dialog("Thank you for noticing this notice.", "Notice!");
		Dialog.ShowAsync();
	}

	void KeyDown(CoreWindow^ Window, KeyEventArgs^ Args)
	{
		if (Args->VirtualKey == VirtualKey::A)
		{
			// do something...
			MessageDialog Dialog("Thank you for noticing this notice.", "Notice!");
			Dialog.ShowAsync();
		}

	}

	//in Unity3D this would be the equivalent to the following code:
	//String moveUp = w;
	//void Update()
	//{
	//   if(Input.GetKeyDown(moveUp)
	//   ....
	//}

	//Something to think about is how to put your program in a "Suspend" state since we should learn how to utilize the life-cycle.
	//The suspend state will be in charge of saving any game or app data that you want to store.
	//The tutorial I am following explains that the Suspend state is now a Window event, but a Application event, although they are similair. 
	//refer to Initialize()->CoreApplication::Suspend... syntax
	void Suspending(Object^ Sender, SuspendingEventArgs^ Args) {}

	void Resuming(Object^ Sender, Object^ Args) {}

	void Closed(CoreWindow^ sender, CoreWindowEventArgs^ args)
	{
		WindowClosed = true;    // Time to end the endless loop
	}
};


// the class definition that creates an instance of our core framework class
ref class AppSource sealed : IFrameworkViewSource
{
public:
	virtual IFrameworkView^ CreateView()
	{
		return ref new App();    // create an App class and return it
	}

	
};

[MTAThread]    // define main() as a multi-threaded-apartment function

// the starting point of all programs
int main(Array<String^>^ args)
{
	CoreApplication::Run(ref new AppSource());    // create and run a new AppSource class
	return 0;
}