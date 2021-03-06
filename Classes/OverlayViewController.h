#import <UIKit/UIKit.h>
#import <AudioToolbox/AudioServices.h>

@protocol OverlayViewControllerDelegate;

@interface OverlayViewController : UIViewController <UINavigationControllerDelegate, UIImagePickerControllerDelegate> {
  id <OverlayViewControllerDelegate> delegate;
  UIImagePickerController *imagePickerController;
  
@private
  UIBarButtonItem *takePictureButton;
  UIBarButtonItem *cancelButton;
  
  SystemSoundID tickSound;
}    

@property (nonatomic, assign) id <OverlayViewControllerDelegate> delegate;
@property (nonatomic, retain) UIImagePickerController *imagePickerController;

@property (nonatomic, retain) IBOutlet UIBarButtonItem *takePictureButton;
@property (nonatomic, retain) IBOutlet UIBarButtonItem *cancelButton;

- (void)setupImagePicker;
- (IBAction)done:(id)sender;
- (IBAction)takePhoto:(id)sender;

@end



@protocol OverlayViewControllerDelegate
- (void)didTakePicture:(UIImage *)picture;
- (void)didFinishWithCamera;
@end
