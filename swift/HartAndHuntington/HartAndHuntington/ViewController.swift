//
//  ViewController.swift
//  HartAndHuntington
//
//  Created by SecondForm.com on 10/26/14.
//  Copyright (c) 2014 HartAndHuntington. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    
    
    @IBOutlet var imageView: UIImageView!
    @IBAction func nextButton(sender: AnyObject) {
        //let vc = StepTwoViewController(nibName: "StepTwoViewController", bundle: nil)
        
        let storyboard = UIStoryboard(name:"Main", bundle:nil)
        let vc = storyboard.instantiateViewControllerWithIdentifier("table") as UITableViewController
        //let vc = TableViewController()
        //TableViewController()
        navigationController?.pushViewController(vc, animated: true)
    }
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
        let  image1 = UIImage(named:"artists.png")
        
        //let artists_placeholder = UIImageView(image:image1)
        //artists_placeholder.frame = self.view.frame
        //artists_placeholder.frame = CGRectMake(10, 10, 200, 200)
        //self.view.addSubview(artists_placeholder)
        
        imageView.image = image1
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

